/*
  ==============================================================================

    MidiProcessor.h
    Created: 27 Dec 2019 2:35:46pm
    Author:  phili

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MidiProcessor
{
public:
  explicit MidiProcessor(AudioProcessorValueTreeState& vts);
  ~MidiProcessor();

  void process(MidiBuffer& midi_messages);

private:
  MidiBuffer p_midi_buffer_;

  AudioProcessorValueTreeState& vts_;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiProcessor)
};
