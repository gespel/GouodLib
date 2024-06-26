#pragma once
#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include "Function.h"
#include "Tools.h"
#include "StdFunctions.h"

class Interpreter {
public:
    Interpreter(std::map<std::string, double> initVariables);
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
    double callFunction(std::string functionName, std::vector<double> args);
    void printTokens(std::vector<std::pair<TokenType, std::string>> tokens);
    bool logic(std::vector<std::pair<TokenType, std::string>> tokens);
    int index = 0;
    bool expect(TokenType, std::pair<TokenType, std::string> token);
};
