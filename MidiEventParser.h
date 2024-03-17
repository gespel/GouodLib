#include "JuceHeader.h"
#include <iostream>

class MidiEventParser {
public:
    MidiEventParser(double sampleRate);
    std::vector<double> parseMidiToNote(juce::MidiBuffer *midiMessages);
private:
    
};