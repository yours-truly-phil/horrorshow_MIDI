/*
  ==============================================================================

    MidiProcessor.h
    Created: 27 Dec 2019 2:35:46pm
    Author:  phili

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MidiProcessor
{
public:
  void process(MidiBuffer& midiMessages)
  {
    p_midi_buffer_.clear();

    MidiBuffer::Iterator it(midiMessages);
    MidiMessage currentMessage;
    int samplePos;

    while(it.getNextEvent(currentMessage, samplePos))
    {
      if(currentMessage.isNoteOnOrOff())
      {
        // TODO: process neg harmony
      }
      p_midi_buffer_.addEvent(currentMessage, samplePos);
    }
    midiMessages.swapWith(p_midi_buffer_);
  }

private:
  MidiBuffer p_midi_buffer_;
};
