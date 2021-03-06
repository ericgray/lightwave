#include "includes.h"

BOOLEAN
EventLogIsCmdLineOption(
    char* arg
)
{
    return ( IsNullOrEmptyString( arg ) == FALSE )
           &&
           ( arg[0] == '-' );
}

DWORD
EventLogParseArgs(
    int         argc,
    char*       argv[],
    PBOOLEAN    pbConsoleMode
    )
{
    DWORD dwError = ERROR_SUCCESS;
    int i = 1; // first arg is the <name of exe>.exe

    while( i < argc )
    {
        if( EventLogIsCmdLineOption( argv[i] ) != FALSE )
        {
            if ( EventLogStringCompareA(
                            VMEVENT_OPTION_ENABLE_CONSOLE, argv[i], TRUE ) == 0 )
            {
                if ( pbConsoleMode != NULL )
                {
                    *pbConsoleMode = TRUE;
                }
            }
            else
            {
                dwError = ERROR_INVALID_PARAMETER;
                BAIL_ON_VMEVENT_ERROR(dwError);
            }
        }

        i++;
    } // while

error:

    return dwError;
}

DWORD
EventLogAllocateArgsAFromArgsW(
    int argc,
    WCHAR* argv[],
    PSTR** argvA
)
{
    DWORD dwError = ERROR_SUCCESS;
    char** retArgV = NULL;

    if ( argvA == NULL )
    {
        dwError = ERROR_INVALID_PARAMETER;
        BAIL_ON_VMEVENT_ERROR(dwError);
    }
    *argvA = NULL;

    if ( (argc > 0) && ( argv != NULL ) )
    {
        int i = 0;
        dwError = EventLogAllocateMemory(
            argc*sizeof(char*), (PVOID*)(&retArgV) );
        BAIL_ON_VMEVENT_ERROR(dwError);
        for(i = 0; i < argc; i++)
        {
            if( IsNullOrEmptyString( argv[i] ) == FALSE )
            {
                dwError = EventLogAllocateStringAFromW( argv[i], (retArgV + i));
                BAIL_ON_VMEVENT_ERROR(dwError);
            }
            else
            {
                retArgV[i] = NULL;
            }
        }
    }

    *argvA = retArgV;
    retArgV = NULL;

error:

    EventLogDeallocateArgsA( argc, retArgV );
    retArgV = NULL;

    return dwError;
}

VOID
EventLogDeallocateArgsA(
    int argc,
    PSTR argv[]
)
{
    if ( (argc > 0) && ( argv != NULL ) )
    {
        int i = 0;
        for(i = 0; i < argc; i++)
        {
            if(argv[i] != NULL)
            {
                EventLogFreeStringA( argv[i] );
                argv[i] = NULL;
            }
        }
        EventLogFreeMemory( argv );
    }
}
