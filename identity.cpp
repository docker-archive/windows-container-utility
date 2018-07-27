#include "containerutility.h"

int GetAccountSid(ArgumentStream* Arguments)
{
    wchar_t* accountName = Arguments->GetArgument();

    if (accountName == nullptr) {
        fprintf(stderr, "Usage:  containerutility getaccountsid accountname\n\n");
        return ERROR_INVALID_PARAMETER;
    }

    Arguments->Advance();

    wchar_t* sidBuffer = new wchar_t[MAX_SID_SIZE];
    PSID sid = (PSID) sidBuffer;
    LPTSTR referencedDomain = (LPTSTR) new wchar_t[MAX_PATH];
    DWORD sidLength = MAX_SID_SIZE;
    DWORD referencedDomainLength = MAX_PATH;
    SID_NAME_USE sidNameUse;

    if (LookupAccountName(nullptr, accountName, sid, &sidLength, referencedDomain, &referencedDomainLength, &sidNameUse) == false) {
        LPTSTR messageBuffer;

        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&messageBuffer, 0, NULL);

        fprintf(stderr, "%S\n", messageBuffer);

        delete[] sidBuffer;
        delete[] referencedDomain;

        return GetLastError();
    }

    LPTSTR stringSid = nullptr;

    if (ConvertSidToStringSid(sid, &stringSid) != false) {
        fprintf(stdout, "%S", stringSid);
        LocalFree(stringSid);

    } else {
        LPTSTR messageBuffer;

        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&messageBuffer, 0, NULL);

        fprintf(stderr, "%S\n", messageBuffer);

        delete[] sidBuffer;
        delete[] referencedDomain;
        
        return GetLastError();
    }

    delete[] sidBuffer;
    delete[] referencedDomain;

    return ERROR_SUCCESS;
}