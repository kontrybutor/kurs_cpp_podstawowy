#include "validation.hpp"

#include <map>
using EC = ErrorCode;

std::string getErrorMessage(const ErrorCode &err)
{
    std::string result;
    std::map<ErrorCode, std::string> errorMap = {
        {EC::Ok, "YourPasswordIsOK"},
        {EC::PasswordNeedsAtLeastNineCharacters, "NeedsAtLeastNineCharacters"},
        {EC::PasswordNeedsAtLeastOneNumber, "NeedsAtLeastOneNumber"},
        {EC::PasswordNeedsAtLeastOneSpecialCharacter, "NeedsOneSpecialCharacter"},
        {EC::PasswordNeedsAtLeastOneUppercaseLetter, "NeedsAtLeastOneUppercaseLetter"},
        {EC::PasswordsDoesNotMatch, "PasswordsDoesNotMatch"}};

    if (errorMap.contains(err))
    {
        result = errorMap[err];
    }
    return result;
}

bool doesPasswordsMatch(const std::string &passwd1,
                        const std::string &passwd2)
{
    bool result = false;
    if (passwd1 == passwd2)
    {
        result = true;
    }
    return result;
}

ErrorCode checkPasswordRules(const std::string &passwd)
{
    ErrorCode err;

    return err;
}

ErrorCode checkPassword(const std::string &passwd1,
                        const std::string &passwd2)
{

    if (doesPasswordsMatch(passwd1, passwd2))
    {
        return ErrorCode::Ok;
    }
    return ErrorCode::PasswordsDoesNotMatch;
}