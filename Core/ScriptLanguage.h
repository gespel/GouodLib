/*
  ==============================================================================

    ScriptLanguage.h
    Created: 28 Sep 2023 12:50:07pm
    Author:  sheimbrodt

  ==============================================================================
*/
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Synths.h"

class ScriptInterpreter {
public:
    ScriptInterpreter();
    void interpret();
private:
    std::ifstream synthdef;
    std::ifstream songdef;
    std::vector<std::tuple<Synth*, std::string>> synths;
};