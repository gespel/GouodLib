#include "JuceHeader.h"
#include <iostream>

class MidiEventParser {
public:
    MidiEventParser(double sampleRate);
    std::vector<double> handle(juce::MidiBuffer *midiMessages);
private:
    
};