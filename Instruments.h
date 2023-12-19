#include "Synths.h"
#include <memory>
#include <tuple>

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
    GKick(double sampleRate);
    double getSample();
    void trigger();
    
private:
    int mastertimer;
    double sampleRate;
    int length = 5000;
    bool active = false;
    SineSynth *base;
};
