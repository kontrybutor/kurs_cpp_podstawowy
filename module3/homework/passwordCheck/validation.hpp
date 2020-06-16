#pragma once

#include <string>

enum class ErrorCode
{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode err);

bool doesPasswordsMatch(const std::string& passwd1, const std::string& passwd2);

ErrorCode checkPasswordRules(const std::string& passwd);

ErrorCode checkPassword(const std::string& passwd1, const std::string& passwd2);
