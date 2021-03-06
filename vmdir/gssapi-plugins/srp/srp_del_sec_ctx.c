/*
 * Copyright © 2012-2015 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the “License”); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */



#include "gssapiP_srp.h"
#include "includes.h"
#include "srprpc.h"
#include <client/structs.h>
#include <csrp/srp.h>

/*
 * Cleanup SRP client-side memory. SRP server-side binding handle
 * and SRP verifier handle are cleaned up by srp_gss_accept_sec_context()
 * when the authentication exchange is complete, pass or fail.
 * Note: calling these cleanup routines here causes a hang;
 *       the reason is unknown.
 */
OM_uint32
srp_gss_delete_sec_context(
                OM_uint32 *minor_status,
                gss_ctx_id_t *context_handle,
                gss_buffer_t output_token)
{
    srp_gss_ctx_id_t srp_ctx = NULL;
    OM_uint32 tmp_minor = GSS_S_COMPLETE;
    OM_uint32 ret = GSS_S_COMPLETE;

    if (context_handle == NULL)
    {
        return (GSS_S_FAILURE);
    }

    srp_ctx = (srp_gss_ctx_id_t) *context_handle;

    if (srp_ctx->upn_name)
    {
        free(srp_ctx->upn_name);
    }

    if (srp_ctx->gss_upn_name)
    {
        gss_release_name(&tmp_minor, &srp_ctx->gss_upn_name);
    }

    if (srp_ctx->srp_session_key)
    {
        free(srp_ctx->srp_session_key);
    }

    if (srp_ctx->srp_usr)
    {
        srp_user_delete(srp_ctx->srp_usr);
        srp_ctx->srp_usr = NULL;
    }

#ifdef _WIN32
    /*
     * Due to differences between GSSAPI 1.7 (likewise) vs 1.11.3 (windows kfw),
     * the management of this memory is handled differently. As this is allocated
     * in srp_gss_accept_sec_context(), this *should* be memory owned by the
     * SRP plugin, and therefore our responsibility to free. GSSAPI 1.7
     * disagrees, and frees this memory for us. Enabling this code on Linux
     * causes double free, and heap corruption. This most likely is
     * a bug in GSSAPI 1.7, as this behavior is not seen in 1.11.3.
     *
     * Note: This has been run through valgrind (linux) and Purify (win32) and
     * no memory leaks or invalid accesses are reported for srp_ctx->mech.
     */
    if (srp_ctx->mech)
    {
        gss_release_oid(&tmp_minor, &srp_ctx->mech);
    }
#endif

    if (srp_ctx->krb5_ctx)
    {
        if (srp_ctx->keyblock)
        {
            krb5_free_keyblock_contents(srp_ctx->krb5_ctx, srp_ctx->keyblock);
            free(srp_ctx->keyblock);
            srp_ctx->keyblock = NULL;
        }

        krb5_free_context(srp_ctx->krb5_ctx);
        srp_ctx->krb5_ctx = NULL;
    }

    HMAC_CTX_cleanup(&srp_ctx->hmac_ctx);

    free(*context_handle);
    *context_handle = NULL;
    return (ret);
}
