/*
  ==============================================================================

    MidiProcessor.h
    Created: 27 Dec 2019 2:35:46pm
    Author: phili

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MidiProcessor : AudioProcessorValueTreeState::Listener
{
public:
    explicit MidiProcessor (AudioProcessorValueTreeState& vts);
    ~MidiProcessor() override;

    void processMidiMsgsBlock (MidiBuffer& midi_messages);

private:
    void parameterChanged (const String& parameter_id, float new_value) override;

    int getNegHarmNn (int nn);

    MidiBuffer p_midi_buffer_;

    AudioProcessorValueTreeState& apvts_;

    std::atomic<float>* is_on_;
    std::atomic<float>* cur_key_;
    //  std::atomic<float>* cur_tonic_;

    bool state_changed_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiProcessor)
};
