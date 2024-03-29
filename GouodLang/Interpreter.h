#pragma once
#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>


class Interpreter {
public:
    Interpreter();
    double interpret(std::vector<std::pair<TokenType, std::string>> tokens);
    void printDebug();
    void incIndex();
private:
    std::map<std::string, double> variables;
    std::map<std::string, std::vector<std::pair<TokenType, std::string>>> functions;
    double evaluate(std::vector<std::pair<TokenType, std::string>> tokens);
    double terminal(std::vector<std::pair<TokenType, std::string>> tokens, int sindex);
    double expression(std::vector<std::pair<TokenType, std::string>> tokens);
    int index = 0;
};