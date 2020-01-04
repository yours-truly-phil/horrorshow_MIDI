/*
  ==============================================================================

    MidiProcessor.cpp
    Created: 2 Jan 2020 3:33:19pm
    Author:  phili

  ==============================================================================
*/

#include "MidiProcessor.h"

#include "PluginProcessor.h"

MidiProcessor::MidiProcessor(AudioProcessorValueTreeState& vts) : apvts_(vts)
{
  p_nn_up_bound_ = apvts_.getRawParameterValue(kIdMaxMidiNoteNumber);
  p_nn_low_bound_ = apvts_.getRawParameterValue(kIdMinMidiNoteNumber);
  //p_nn_bounds_ = {p_nn_low_bound_,p_nn_up_bound_};
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
      auto nn = current_message.getNoteNumber();
      nn = nn + (60 - nn) * 2;
      current_message.setNoteNumber(nn);
      //current_message = transform(current_message.getNoteNumber()*, -20);
    }
    p_midi_buffer_.addEvent(current_message, sample_pos);
  }
  midi_messages.swapWith(p_midi_buffer_);
}
