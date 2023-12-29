#include "MidiEventParser.h"

MidiEventParser::MidiEventParser(double sampleRate) {

}

std::vector<double> MidiEventParser::handle(juce::MidiBuffer *midiMessages) {
    //std::cout << "Called MidiParser handler" << std::endl;
    std::vector<double> out;
    for (const auto metadata : (*midiMessages)) {
        auto message = metadata.getMessage();
        const auto time = metadata.samplePosition;

        if (message.isNoteOn()) {
            auto note = juce::MidiMessage::getMidiNoteInHertz(message.getNoteNumber());
            out.push_back(note);
            std::cout << juce::MidiMessage::getMidiNoteName(message.getNoteNumber(), true, true, 4) << std::endl;

            
        }
        else if (message.isNoteOff()) {
            
        }
    }
    return out;
}