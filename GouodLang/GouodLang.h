#include "Core/Interpreter.h"
#include "Core/Lexer.h"

class GouodLang {
public:
    GouodLang();
    void interpretFile(std::string filePath);
    void interpretString(std::string input);
private:
    Interpreter interpreter;
    Lexer lexer;
};