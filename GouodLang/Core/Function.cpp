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

std::vector<std::string> Function::getArguments() {
    return args;
}

void Function::printFunctionTokens() {
    for(auto token : tokens) {
        std::cout << token.second << std::endl;
    }
}
