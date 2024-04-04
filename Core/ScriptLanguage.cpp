/*
  ==============================================================================

    ScriptLanguage.cpp
    Created: 28 Sep 2023 12:50:07pm
    Author:  sheimbrodt

  ==============================================================================
*/

#include "ScriptLanguage.h"

ScriptInterpreter::ScriptInterpreter() {
    this->synthdef = std::ifstream("synths.txt");
    this->songdef = std::ifstream("song.txt");

    if (!this->synthdef) {
        std::cerr << "Error while opening synths.txt" << std::endl;
    }
    if (!this->songdef) {
        std::cerr << "Error while opening song.txt" << std::endl;
    }
}

void ScriptInterpreter::interpret() {
    std::vector<std::string> zeile;
    std::string teil;
    while (std::getline(this->synthdef, teil, ' ')) {
        zeile.push_back(teil);
        std::cout << teil << std::endl;
    }
}