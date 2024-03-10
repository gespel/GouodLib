#include "Synths.h"
#include <memory>
#include <tuple>
#include <iostream>
#include <cstdlib>
#include <ctime>

class StrangeOrgan {
public:
    StrangeOrgan(double freq, double sampleRate);
    std::tuple<double, double> getSample();
    void setFrequency(double freq);
    void setModulatorFrequency(double freq);
private:
    double sampleRate;
    double freq;
    std::unique_ptr<FMSynth> fs1L;
    std::unique_ptr<FMSynth> fs2L;
    std::unique_ptr<FMSynth> fs1R;
    std::unique_ptr<FMSynth> fs2R;
};

class GKick {
public:
    GKick(double freq, double sampleRate);
    double getSample();
    void trigger();
    double getAddKickAttackEnvelope();
    
private:
    double freq;
    int mastertimer;
    double sampleRate;
    int length = 13000;
    bool active = false;
    SineSynth *base;
    SawtoothSynth *transient;
    int addKickEnvelopeTimer;
};

class GHat {
public:
    GHat(double freq, double sampleRate);
    std::tuple<double, double> getSample();
    void trigger();
private:
    double freq;
    int mastertimer;
    double sampleRate;
    int length = 20000;
    bool active = false;
    WhiteNoiseSynth *main;
    
};

class PadDrone {
public:
    PadDrone(double freq, double sampleRate);
    std::tuple<double, double> getSample();
    void setFrequency(double freq);
private:
    double sampleRate;
    double freq;
    SawtoothSynth *pd1;
    SawtoothSynth *pd2;
    SawtoothSynth *pd3;
    SawtoothSynth *pd4;

    SawtoothSynth *pd5;
};

class MegaDrone {
public:
    MegaDrone(double freq, int numVoices, double sampleRate);
    std::tuple<double, double> getSample();
    void setFrequency(double freq);
private:
    double sampleRate;
    double freq;
    std::vector<SawtoothSynth> synths;
};
