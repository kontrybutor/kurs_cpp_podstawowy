#include "validation.hpp"

#include <algorithm>
#include <map>

using EC = ErrorCode;

std::string getErrorMessage(const ErrorCode &err)
{
    std::string message;
    std::map<ErrorCode, std::string> errorMap = {
        {EC::Ok, "YourPasswordIsOK"},
        {EC::PasswordNeedsAtLeastNineCharacters, "NeedsAtLeastNineCharacters"},
        {EC::PasswordNeedsAtLeastOneNumber, "NeedsAtLeastOneNumber"},
        {EC::PasswordNeedsAtLeastOneSpecialCharacter, "NeedsOneSpecialCharacter"},
        {EC::PasswordNeedsAtLeastOneUppercaseLetter, "NeedsAtLeastOneUppercaseLetter"},
        {EC::PasswordsDoesNotMatch, "PasswordsDoesNotMatch"}};

    if (errorMap.find(err) != errorMap.end())
    {
        message = errorMap[err];
    }
    return message;
}

bool doesPasswordsMatch(const std::string &passwd1,
                        const std::string &passwd2)
{
    return passwd1 == passwd2;
}

ErrorCode checkPasswordRules(const std::string &passwd)
{
    EC err = EC::Ok;

    if (std::any_of(passwd.begin(), passwd.end(), ::isupper))
    {
        err = EC::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    if (std::any_of(passwd.begin(), passwd.end(),
                    [](const auto c) { return !isalnum(c); }))
    {
        err = EC::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::any_of(passwd.begin(), passwd.end(), ::isdigit))
    {
        err = EC::PasswordNeedsAtLeastOneNumber;
    }
    if (passwd.length() < 9)
    {
        err = EC::PasswordNeedsAtLeastNineCharacters;
    }
    return err;
}

ErrorCode checkPassword(const std::string &passwd1,
                        const std::string &passwd2)
{
    if (doesPasswordsMatch(passwd1, passwd2))
    {
        return EC::Ok;
    }
    return EC::PasswordsDoesNotMatch;
}
