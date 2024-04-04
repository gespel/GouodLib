#include "Function.h"

Function::Function(std::string name, std::vector<std::pair<TokenType, std::string>> tokens, std::vector<std::string> args) {
    this->name = name;
    this->tokens = tokens;
    this->args = args;
}

std::vector<std::pair<TokenType, std::string>> Function::getTokens() {
    return tokens;
}

std::string Function::getName() {
    return name;
}