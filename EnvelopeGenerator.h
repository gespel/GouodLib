/*
  ==============================================================================

    EnvelopeGenerator.h
    Created: 13 Jul 2023 6:31:17pm
    Author:  Sten

  ==============================================================================
*/

#pragma once

class EnvelopeGenerator {
public:
    EnvelopeGenerator(double sampleRate, double freq);
    double getSample();
    void setMax(double newmax);
    void setMin(double newmin);
    void setFrequency(double newfreq);
    
protected:
    virtual void tick() {};
    double sampleRate;
    double freq;
    double max = 1;
    double min = 0;
    double sample = 0;
    double phase = 0;
};

class SawtoothEnvelopeIncreasing : public EnvelopeGenerator {
public:
    SawtoothEnvelopeIncreasing(double sampleRate, double freq);
    
private:
    void tick() override;
    
    
};

class SawtoothEnvelopeDecreasing : public EnvelopeGenerator {
public:
    SawtoothEnvelopeDecreasing(double sampleRate, double freq);

private:
    void tick() override;
};
