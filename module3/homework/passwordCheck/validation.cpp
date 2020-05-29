#include "validation.hpp"

#include <map>
using EC = ErrorCode;

std::string getErrorMessage(const ErrorCode &err) {

    const std::map<ErrorCode, std::string> errorMap = {
        {EC::Ok, "OK"},
        {EC::PasswordNeedsAtLeastNineCharacters, "NeedsAtLeastNineCharacters"},
        {EC::PasswordNeedsAtLeastOneNumber, "NeedsAtLeastOneNumber"},
        {EC::PasswordNeedsAtLeastOneSpecialCharacter, "NeedsOneSpecialCharacter"},
        {EC::PasswordNeedsAtLeastOneUppercaseLetter, "NeedsAtLeastOneUppercaseLetter"},
        {EC::PasswordsDoesNotMatch, "PasswordsDoesNotMatch"}
        };

    return "";
}

bool doesPasswordsMatch(const std::string &passwd1,
                        const std::string &passwd2) {
    return false;
}

ErrorCode checkPasswordRules(const std::string &passwd) {
    ErrorCode err;

    return err;
}

ErrorCode checkPassword(const std::string &passwd1,
                        const std::string &passwd2) {
    ErrorCode err;

    return err;
}