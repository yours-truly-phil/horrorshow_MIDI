/*
  ==============================================================================

    MidiProcessor.cpp
    Created: 2 Jan 2020 3:33:19pm
    Author:  phili

  ==============================================================================
*/

#include "MidiProcessor.h"

MidiProcessor::MidiProcessor(AudioProcessorValueTreeState& vts) : vts_(vts)
{
}

MidiProcessor::~MidiProcessor()
= default;


void MidiProcessor::process(MidiBuffer& midi_messages)
{
  p_midi_buffer_.clear();

  MidiBuffer::Iterator it(midi_messages);
  MidiMessage current_message;
  int sample_pos;

  while (it.getNextEvent(current_message, sample_pos))
  {
    if (current_message.isNoteOnOrOff())
    {
      // TODO
    }
    p_midi_buffer_.addEvent(current_message, sample_pos);
  }
  midi_messages.swapWith(p_midi_buffer_);
}
