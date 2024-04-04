#include "Function.h"

Function::Function(std::string name, std::vector<std::pair<TokenType, std::string>> tokens, std::vector<std::string> args) {
    this->name = name;
    this->tokens = tokens;
    this->args = args;
}

double Function::execute() {
    //Interpreter i;
    //std::cout << "Calling function: " << functionName << std::endl;
    for(int i = 0; i < tokens.size(); i++) {
        //std::cout << functionTokens[i].second << std::endl;
        //incIndex();
    }
    //printTokens(functionTokens);
    //return i.interpret(tokens);
    return 0;
}

std::vector<std::pair<TokenType, std::string>> Function::getTokens() {
    return tokens;
}

std::string Function::getName() {
    return name;
}