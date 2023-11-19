/*
  ==============================================================================

    Randoneur.h
    Created: 28 Jun 2023 8:44:35pm
    Author:  Sten

  ==============================================================================
*/

#pragma once
#include "Synths.h"
#include "stdlib.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Randoneur {
public:
    Randoneur(int synthcount);
    std::vector<Synth*> randomRack;
    std::vector<double> volumeTable;
    double getSample();
    
private:
    int synthcount = 0;
};
