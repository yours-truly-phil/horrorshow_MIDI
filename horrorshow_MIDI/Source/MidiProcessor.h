/*
  ==============================================================================

    MidiProcessor.h
    Created: 14 Dec 2019 3:10:01pm
    Author:  phili

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MidiProcessor
{
public:
    void process(MidiBuffer& midi_buffer)
    {
        MidiBuffer::Iterator iterator(midi_buffer);
        MidiMessage message;
        int pos;

        while (iterator.getNextEvent(message, pos))
        {
            DBG(message.getDescription());
        }
    }
};
