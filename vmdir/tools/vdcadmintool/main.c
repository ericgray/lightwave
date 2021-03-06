#include "includes.h"

#ifndef _WIN32
int main(int argc, char* argv[])
#else
int _tmain(int argc, TCHAR *targv[])
#endif
{
    while (1)
    {
        CHAR pszChoice[3] = { '\0' };
        int choice = -1;

        VmDirReadString(
            "\n\n==================\n"
            "Please select:\n"
            "0. exit\n"
            "1. Test LDAP connectivity\n"
            "2. Force start replication cycle\n"
            "3. Reset account password\n"
            "4. Set log level and mask\n"
            "5. Set vmdir state\n"
//            "99. Set SRP Authentication data\n"  do not want to expose this to users.  internal test only.
            "==================\n\n",
            pszChoice,
            sizeof(pszChoice),
            FALSE);

        choice = atoi(pszChoice);

        if (!choice)
        {
            goto cleanup;
        }

        switch (choice)
        {
          case 1:
              VdcadminTestSASLClient();
              break;

          case 2:
              VdcadminReplNow();
              break;

          case 3:
              VdcadminForceResetPassword();
              break;

          case 4:
              VdcadminSetLogParameters();
              break;

          case 5:
              VdcadminSetVmdirState();
              break;

          case 99:
              VdcadminSetSRPAuthData();
              break;

          default:
              goto cleanup;
        }
    }

cleanup:

    return 0;

}
