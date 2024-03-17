#include "LichtenKick.h"


LichtenKick::LichtenKick(double sampleRate) {
    this->sampleRate = sampleRate;
    this->base = new SineSynth(55, sampleRate); 
    this->active = false;
    this->mastertimer = 0;              
}

std::tuple<double, double> LichtenKick::getSample() {
    if(active) {
        mastertimer++;
        auto out = base->getSample() * (1 - ((double)mastertimer/(double)length));
        base->setFrequency(220.f * (1 - ((double)mastertimer/(double)length)));

        //Kicksynthesis
        if(mastertimer >= length) {
            active = false;
            mastertimer = 0;
            addKickEnvelopeTimer = 0;
            base->resetPhase();
        }
        return std::make_tuple(out, out);
    }
    else {
        return std::make_tuple(0, 0);
    }
}