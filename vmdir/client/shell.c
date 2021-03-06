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



/*
 * Module Name: common
 *
 * Filename: shell.c
 *
 * Abstract:
 *
 * shell commands
 *
 */

#include "includes.h"

DWORD
VmDirStartService(
    VOID
    )
{
    return VmDirRun(VMDIR_START_SERVICE);
}

DWORD
VmDirStopService(
    VOID
    )
{
    return VmDirRun(VMDIR_STOP_SERVICE);
}

DWORD
VmDirCleanupData(
    VOID
    )
{
    return VmDirRun(VMDIR_CLEANUP_DATA);
}

DWORD
VmDirResetVmdir(
    VOID)
{
    DWORD dwError = 0;

    dwError = VmDirStopService();
    BAIL_ON_VMDIR_ERROR(dwError);

    //Test for bug#1034595. On Windows, vmdird may fail to stop. Wait 2 seconds here.
    //Remove it if it's not useful
    VmDirSleep(2000);

    dwError = VmDirCleanupData();
    BAIL_ON_VMDIR_ERROR(dwError);

    dwError = VmDirStartService();
    BAIL_ON_VMDIR_ERROR(dwError);

error:
    return dwError;
}

DWORD
VmKdcStartService(
    VOID
    )
{
    return VmDirRun(VMKDC_START_SERVICE);
}

DWORD
VmKdcStopService(
    VOID
    )
{
    return VmDirRun(VMKDC_STOP_SERVICE);
}

DWORD
VmDirGetVmDirLogPath(
    PSTR  pszPath,
    PCSTR pszLogFile)
{
    DWORD dwError = 0;

#ifndef _WIN32
    //BUGBUG, should NOT hard code path
    dwError = VmDirStringCpyA(pszPath, MAX_PATH, "/var/log/vmware/vmdir/");
    BAIL_ON_VMDIR_ERROR(dwError);
#else
    _TCHAR* programDataPath           = NULL;

    if ((dwError = VmDirGetRegKeyValue( VMDIR_CONFIG_SOFTWARE_KEY_PATH, VMDIR_REG_KEY_LOG_PATH, pszPath,
                                        MAX_PATH )) != 0)
    {
       dwError = VmDirGetProgramDataEnvVar((_TCHAR *)"PROGRAMDATA", &programDataPath);
       BAIL_ON_VMDIR_ERROR(dwError);

       dwError = VmDirStringPrintFA(pszPath, MAX_PATH, "%s%s", programDataPath, "\\vmware\\cis\\logs\\vmdird\\");
       BAIL_ON_VMDIR_ERROR(dwError);
    }
#endif

    dwError = VmDirStringCatA(pszPath, MAX_PATH, pszLogFile);
    BAIL_ON_VMDIR_ERROR(dwError);

cleanup:
#ifdef _WIN32
    VMDIR_SAFE_FREE_MEMORY(programDataPath);
#endif
    return dwError;
error:
    VmDirLog(LDAP_DEBUG_ERROR, "VmDirGetVmDirLogPath failed with error (%u)\n", dwError);
    goto cleanup;
}
