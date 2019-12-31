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
  void process(MidiBuffer& midi_messages)
  {
    p_midi_buffer_.clear();

    MidiBuffer::Iterator it(midi_messages);
    MidiMessage current_message;
    int sample_pos;

    while(it.getNextEvent(current_message, sample_pos))
    {
      if(current_message.isNoteOnOrOff())
      {
        // TODO: process neg harmony
      }
      p_midi_buffer_.addEvent(current_message, sample_pos);
    }
    midi_messages.swapWith(p_midi_buffer_);
  }

private:
  MidiBuffer p_midi_buffer_;
};
