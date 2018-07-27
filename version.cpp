#include "containerutility.h"

int PrintVersion(ArgumentStream* Arguments)
{
    fprintf(stdout, "containerutility %S\n", DOCKERUTIL_VERSION);

    return ERROR_SUCCESS;
}