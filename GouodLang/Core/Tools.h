#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "TokenType.h"

class Tools {
public:
    static std::string createStringFromTokens(std::vector<std::pair<TokenType, std::string>> tokens) {
        std::string out = "";
        for(auto const t : tokens) {
            out += t.second + " ";
        }
        return out;
    }
};
