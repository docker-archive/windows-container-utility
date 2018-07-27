#include "containerutility.h"

void PrintUsage()
{
    fprintf(stderr, "Usage:  containerutility COMMAND\n\n");
    fprintf(stderr, "A utility for performing actions inside containers\n\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  --version        Prints a version and then quits\n\n");
    fprintf(stderr, "Commands:\n");
    fprintf(stderr, "  getaccountsid    Obtains the SID for the specified account\n");
    fprintf(stderr, "\n");
}

int wmain(int argc, wchar_t* argv[])
{
    if (argc < 2) {
        PrintUsage();

        return ERROR_INVALID_PARAMETER;
    }

    ArgumentStream argumentStream(argc-1, &argv[1]);
    COMMAND command;
    int result;

    command = ParseCommand(&argumentStream);

    if (command == COMMAND_INVALID) {
        PrintUsage();

        return ERROR_INVALID_PARAMETER;
    }
    
    switch (command) {
        case COMMAND_GETACCOUNTSID:
            result = GetAccountSid(&argumentStream);
            break;
        case COMMAND_VERSION:
            result = PrintVersion(&argumentStream);
            break;
        default:
            result = ERROR_INVALID_PARAMETER;
            break;
    }

    return result;
}