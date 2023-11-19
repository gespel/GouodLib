/*
  ==============================================================================

    Randoneur.cpp
    Created: 28 Jun 2023 8:44:35pm
    Author:  Sten

  ==============================================================================
*/

#include "Randoneur.h"


Randoneur::Randoneur(int synthcount) {
    this->synthcount = synthcount;
    for(int i = 0; i < synthcount; i++) {
        std::srand((unsigned int)std::time(nullptr));
        int randomNum = std::rand() % 3;
        int randomMul = std::rand() % 4;
        double randomVol = static_cast<double>(std::rand()) / RAND_MAX;
        
        if(randomNum == 0) {
            randomRack.push_back(new SineSynth(110.f * randomMul, 48000));
        }
        else if(randomNum == 1) {
            randomRack.push_back(new SquareSynth(110.f * randomMul, 48000));
        }
        else if (randomNum == 2) {
            randomRack.push_back(new SawtoothSynth(110.f * randomMul, 48000));
        }
        
        volumeTable.push_back(randomVol);
    }
}

double Randoneur::getSample() {
    double out = 0.f;
    for(int i = 0; i < this->synthcount; i++) {
        out = randomRack[i]->getSample() * volumeTable[i];
    }
    return out;
}
