/*
  ==============================================================================

    StepSequencer.h
    Created: 19 Sep 2023 9:23:26pm
    Author:  stenh

  ==============================================================================
*/

#pragma once
#include <stdlib.h>
#include <vector>
#include <random>

class StepSequencer {
public:
    StepSequencer(float sampleRate, std::vector<float> seq);
    void setSequence(std::vector<float> seq);
    void setSpeed(float speed);
    float getSample();
    float getRandomSample();

private:
    float sampleRate;
    std::vector<float> seq;
    float speed;
    float numPerStep;
    int i;
    int counter;
    int randomCounter;
    std::random_device* rd;
    std::mt19937* gen;
    std::uniform_int_distribution<int>* distribution;
};