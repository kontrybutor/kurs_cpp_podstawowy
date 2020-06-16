#include "validation.hpp"

#include <algorithm>
#include <map>
#include <iostream>
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

bool doesPasswordsMatch(const std::string& passwd1,
                        const std::string& passwd2)
{
    return passwd1 == passwd2;
}

ErrorCode checkPasswordRules(const std::string &passwd)
{
    constexpr const auto minAllowedLength = 9;
    if (passwd.length() < minAllowedLength)
    {
        return EC::PasswordNeedsAtLeastNineCharacters;
    }
    if (!std::any_of(passwd.begin(), passwd.end(), ::isupper))
    {
        return EC::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    if (!std::any_of(passwd.begin(), passwd.end(), ::isdigit))
    {
        return EC::PasswordNeedsAtLeastOneNumber;
    }
    if (!std::any_of(passwd.begin(), passwd.end(),
                     [](const auto c) { return !isalnum(c); }))
    {
        return EC::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    return EC::Ok;
}

ErrorCode checkPassword(const std::string& passwd1,
                        const std::string& passwd2)
{
    if (doesPasswordsMatch(passwd1, passwd2))
    {
        return EC::Ok;
    }
    return EC::PasswordsDoesNotMatch;
}
