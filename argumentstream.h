#pragma once
class ArgumentStream
{
public:
    ArgumentStream(int ArgumentCount, wchar_t** Arguments);
    ~ArgumentStream();

    wchar_t* GetArgument();
    void Advance();

protected:
    ArgumentStream();

private:
    wchar_t** m_Arguments;
    unsigned int m_CurrentIndex;
    unsigned int m_NumberOfArguments;
};

