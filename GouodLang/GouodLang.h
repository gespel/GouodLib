#include "Core/Interpreter.h"
#include "Core/Lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>

class GouodLang {
public:
    GouodLang();
    void interpretFile(std::string filePath);
    void interpretString(std::string input);
private:
    Interpreter *interpreter;
    Lexer *lexer;
};
