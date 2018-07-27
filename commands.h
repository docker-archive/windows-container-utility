#pragma once

typedef enum _COMMAND {
    COMMAND_INVALID = -1,
    COMMAND_GETACCOUNTSID = 0,
    COMMAND_VERSION
} COMMAND;

COMMAND ParseCommand(ArgumentStream* Arguments);