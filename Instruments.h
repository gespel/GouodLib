#include "Synths.h"
#include <memory>
#include <tuple>

class StrangeOrgan {
public:
    StrangeOrgan(double freq, double sampleRate);
    std::tuple<double, double> getSample();
    void setFrequency(double freq);
private:
    double sampleRate;
    double freq;
    std::unique_ptr<FMSynth> fs1L;
    std::unique_ptr<FMSynth> fs2L;
    std::unique_ptr<FMSynth> fs1R;
    std::unique_ptr<FMSynth> fs2R;
};