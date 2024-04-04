/*
  ==============================================================================

    EnvelopeGenerator.cpp
    Created: 13 Jul 2023 6:31:17pm
    Author:  Sten

  ==============================================================================
*/

#include "EnvelopeGenerator.h"


EnvelopeGenerator::EnvelopeGenerator(double sampleRate, double freq) {
    this->sampleRate = sampleRate;
    this->freq = freq;
}

void EnvelopeGenerator::setFrequency(double newfreq) {
    this->freq = newfreq;
}


double EnvelopeGenerator::getSample() {
    this->tick();
    return this->sample;
}

void EnvelopeGenerator::setMax(double newmax) {
    this->max = newmax;
}

void EnvelopeGenerator::setMin(double newmin) {
    this->min = newmin;
}

SawtoothEnvelopeIncreasing::SawtoothEnvelopeIncreasing(double sampleRate, double freq) : EnvelopeGenerator(sampleRate, freq) {
    this->sampleRate = sampleRate;
    this->freq = freq;
    
}

void SawtoothEnvelopeIncreasing::tick() {
    this->sample += this->max / this->sampleRate * this->freq;
    if(this->sample > this->max) {
        this->sample = this->min;
    }
}

SawtoothEnvelopeDecreasing::SawtoothEnvelopeDecreasing(double sampleRate, double freq) : EnvelopeGenerator(sampleRate, freq) {
    this->sampleRate = sampleRate;
    this->freq = freq;

}

void SawtoothEnvelopeDecreasing::tick() {
    this->sample -= this->max / this->sampleRate * this->freq;
    if (this->sample < this->min) {
        this->sample = this->max;
    }
}
