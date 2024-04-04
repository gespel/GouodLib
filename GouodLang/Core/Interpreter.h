#pragma once
#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include "Function.h"
#include "Tools.h"

class Interpreter {
public:
    Interpreter();
    double interpret(std::vector<std::pair<TokenType, std::string>> tokens);
    void printDebug();
    void incIndex();
private:
    std::map<std::string, double> variables;
    std::map<std::string, std::vector<std::pair<TokenType, std::string>>> functions;
    std::map<std::string, Function*> newFunctions;
    double evaluate(std::vector<std::pair<TokenType, std::string>> tokens);
    double terminal(std::vector<std::pair<TokenType, std::string>> tokens, int sindex);
    double expression(std::vector<std::pair<TokenType, std::string>> tokens);
    double callFunction(std::string functionName, std::vector<std::tuple<TokenType, std::string>> args);
    void printTokens(std::vector<std::pair<TokenType, std::string>> tokens);
    int index = 0;
};