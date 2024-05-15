#include <iostream>
#include <string>

class StandardFunctions {
public:
    StandardFunctions();
    void execute(std::string name);
    bool functionExists(std::string name);

private:
    std::vector<std::string> functionNames;
    void print(double arg);
};