#include "containerutility.h"

COMMAND ParseCommand(ArgumentStream* Arguments)
{
    wchar_t* commandArgument = Arguments->GetArgument();

    if (commandArgument == nullptr) {
        return COMMAND_INVALID;
    }

    Arguments->Advance();

    if (wcsicmp(commandArgument, L"getaccountsid") == 0) {
        return COMMAND_GETACCOUNTSID;
    }
    if (wcsicmp(commandArgument, L"--version") == 0) {
        return COMMAND_VERSION;
    }

    return COMMAND_INVALID;
}