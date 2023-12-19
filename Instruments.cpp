#include "Instruments.h"

StrangeOrgan::StrangeOrgan(double freq, double sampleRate) {
    this->sampleRate = sampleRate;
    this->freq = freq;

    this->fs1L = std::make_unique<FMSynth>(440.0f, sampleRate);
    this->fs2L = std::make_unique<FMSynth>(220.0f, sampleRate);
    this->fs1L->setModulatorFrequency(100.f);
    this->fs2L->setModulatorFrequency(100.f);

    this->fs1R = std::make_unique<FMSynth>(440.0f, sampleRate);
    this->fs2R = std::make_unique<FMSynth>(220.0f, sampleRate);
    this->fs1R->setModulatorFrequency(100.f);
    this->fs2R->setModulatorFrequency(100.f);
}

std::tuple<double, double> StrangeOrgan::getSample() {
    double outL = 0;
    double outR = 0;

    outL = this->fs1L->getSample();
    outL += this->fs2L->getSample();
    outL *= 0.3f;
    outR = this->fs1R->getSample();
    outR += this->fs2R->getSample();
    outR *= 0.3f;
    return std::make_tuple(outL, outR);
}

void StrangeOrgan::setFrequency(double freq) {
    this->freq = freq;
    this->fs1L->setModulatorFrequency(freq);
    this->fs2L->setModulatorFrequency(freq/2);
    this->fs1R->setModulatorFrequency(freq*1.001);
    this->fs2R->setModulatorFrequency(freq/2*1.001);
}

void StrangeOrgan::setModulatorFrequency(double freq) {
    this->fs1L->setFrequency(freq);
    this->fs2L->setFrequency(freq);
    this->fs1R->setFrequency(freq);
    this->fs2R->setFrequency(freq);
}

GKick::GKick(double sampleRate) {
    this->sampleRate = sampleRate;
    base = new SineSynth(440.f, sampleRate);
}

double GKick::getSample() {
    if(active) {
        mastertimer++;
        auto out = base->getSample() * (1 - ((double)mastertimer/(double)length));
        if(mastertimer%10 == 0) {
            base->setFrequency(220.f * (1 - ((double)mastertimer/(double)length)));
        }
        //Kicksynthesis
        
        if(mastertimer >= length) {
            active = false;
            mastertimer = 0;
        }
        return out;
    }
    else {
        return 0;
    }
}
void GKick::trigger() {
    active = true;
}
