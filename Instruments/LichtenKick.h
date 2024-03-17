#pragma once
#include "../Synths.h"

class LichtenKick {
public:
    LichtenKick(double sampleRate);
    std::tuple<double, double> getSample();

private:
    double sampleRate;
    int mastertimer;
    int length = 13000;
    bool active = false;
    SineSynth *base;
    SawtoothSynth *transient;
    int addKickEnvelopeTimer;
};