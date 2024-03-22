#pragma once
#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>


class Interpreter {
public:
    Interpreter();
    void interpret(std::vector<std::pair<TokenType, std::string>> tokens);
    void printDebug();
private:
    std::map<std::string, double> variables;
    std::map<std::string, std::vector<std::pair<TokenType, std::string>>> functions;
};