#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include "TokenType.h"

class Function {
public:
    Function(std::string name, std::vector<std::pair<TokenType, std::string>> tokens, std::vector<std::string> args);
    std::string getName();
    std::vector<std::pair<TokenType, std::string>> getTokens();
private:
    std::string name;
    std::vector<std::pair<TokenType, std::string>> tokens;
    std::vector<std::string> args;
};