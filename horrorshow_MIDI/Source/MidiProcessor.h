/*
  ==============================================================================

    MidiProcessor.h
    Created: 14 Dec 2019 3:10:01pm
    Author:  phili

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

constexpr int kMajorThird = 4;

class MidiProcessor
{
public:
    void process(MidiBuffer& midi_buffer)
    {
        processed_buffer_.clear();

        processMidiInput(midi_buffer);

        midi_buffer.swapWith(processed_buffer_);
    }

    void addMajorThirdToMidiMessage(MidiMessage message, int pos)
    {
        auto oldNoteNum = message.getNoteNumber();
        message.setNoteNumber(oldNoteNum + kMajorThird);
        processed_buffer_.addEvent(message, pos);
    }

    void processMidiInput(const MidiBuffer& midi_buffer)
    {
        MidiBuffer::Iterator iterator(midi_buffer);
        MidiMessage message;
        int pos;

        while (iterator.getNextEvent(message, pos))
        {
            if (message.isNoteOnOrOff())
            {
                addMajorThirdToMidiMessage(message, pos);
            }
            processed_buffer_.addEvent(message, pos);
        }
    }

private:
    MidiBuffer processed_buffer_;
};
