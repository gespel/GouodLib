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

GKick::GKick(double freq, double sampleRate) {
    this->freq = freq;
    this->sampleRate = sampleRate;
    base = new SineSynth(freq, sampleRate);
    transient = new SawtoothSynth(freq * 4, sampleRate);
}

double GKick::getSample() {
    if(active) {
        mastertimer++;
        auto transientAttackEnvelope = this->getAddKickAttackEnvelope();
        auto out = base->getSample() * (1 - ((double)mastertimer/(double)length));
        out += transient->getSample() * transientAttackEnvelope;
        
        
        base->setFrequency(freq * (1 - ((double)mastertimer/(double)length)));
        transient->setFrequency(freq * 4 * transientAttackEnvelope);
        
        //Kicksynthesis
        
        if(mastertimer >= length) {
            active = false;
            mastertimer = 0;
            addKickEnvelopeTimer = 0;
            base->resetPhase();
            transient->resetPhase();
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

double GKick::getAddKickAttackEnvelope() {
    addKickEnvelopeTimer++;
    if(addKickEnvelopeTimer <= 200) {
        return 1 - (addKickEnvelopeTimer/200);
    }
    else {
        return 0;
    }
}

PadDrone::PadDrone(double freq, double sampleRate) {
    this->sampleRate = sampleRate;
    this->freq = freq;
    this->pd1 = new SawtoothSynth(this->freq, this->sampleRate);
    this->pd2 = new SawtoothSynth(this->freq+1, this->sampleRate);
    this->pd3 = new SawtoothSynth(this->freq/2, sampleRate);
    this->pd4 = new SawtoothSynth((this->freq/2) + 1, sampleRate);
    this->pd5 = new SawtoothSynth((this->freq*2), sampleRate);
}

std::tuple<double, double> PadDrone::getSample() {
    double out = 0;
    out += this->pd1->getSample();
    out += this->pd2->getSample();
    out += this->pd3->getSample();
    out += this->pd4->getSample();
    out += this->pd5->getSample();
    out /= 5;
    return std::make_tuple(out, out);
}

void PadDrone::setFrequency(double freq) {
    this->freq = freq;
}