/*
  ==============================================================================

    StepSequencer.cpp
    Created: 19 Sep 2023 9:23:26pm
    Author:  stenh

  ==============================================================================
*/

#include "StepSequencer.h"

StepSequencer::StepSequencer(float sampleRate, std::vector<float> seq) {
    this->sampleRate = sampleRate;
    this->seq = seq;
    this->speed = 1;
    this->numPerStep = 0;
    this->setSpeed(this->speed);
    this->i = 0;
    this->counter = 0;
    this->randomCounter = 0;
    this->rd = new std::random_device;
    this->gen = new std::mt19937((*rd)());
    this->distribution = new std::uniform_int_distribution<int>(0, this->seq.size() - 1);
}

void StepSequencer::setSequence(std::vector<float> seq) {
    this->seq = seq;
}

void StepSequencer::setSpeed(float speed) {
    this->speed = speed;
    this->numPerStep = (this->sampleRate * (1 / this->speed)) / this->seq.size();
}

float StepSequencer::getSample() {
    if (this->i > this->numPerStep) {
        this->counter++;
        if (this->counter > this->seq.size() - 1) {
            this->counter = 0;
        }
        this->i = 0;
    }
    this->i++;
    return this->seq[this->counter];
}

float StepSequencer::getRandomSample() {
    if (this->i > this->numPerStep) {
        this->randomCounter = (*distribution)(*gen);
        this->i = 0;
    }
    this->i++;
    return this->seq[this->randomCounter];
}