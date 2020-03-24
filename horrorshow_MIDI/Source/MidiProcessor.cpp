/*
  ==============================================================================

    MidiProcessor.cpp
    Created: 2 Jan 2020 3:33:19pm
    Author: phili

  ==============================================================================
*/

#include "MidiProcessor.h"
#include <cfloat>

#include "PluginProcessor.h"

MidiProcessor::MidiProcessor(AudioProcessorValueTreeState &vts) : apvts_(vts)
{
    is_on_ = apvts_.getRawParameterValue(kIdIsProcessingActive);
    //  cur_tonic_ = apvts_.getRawParameterValue(kIdTonicNn);
    cur_key_ = apvts_.getRawParameterValue(kIdKey);

    apvts_.addParameterListener(kIdIsProcessingActive, this);
    //  apvts_.addParameterListener(kIdTonicNn, this);
    apvts_.addParameterListener(kIdKey, this);

    state_changed_ = true;
}

MidiProcessor::~MidiProcessor() = default;

void
MidiProcessor::processMidiMsgsBlock(MidiBuffer &midi_messages)
{
    p_midi_buffer_.clear();

    MidiBuffer::Iterator it(midi_messages);
    MidiMessage cur_msg;
    int sample_pos;

    while (it.getNextEvent(cur_msg, sample_pos))
    {
        if (cur_msg.isNoteOnOrOff())
        {
            if (state_changed_)
            {
                p_midi_buffer_.addEvent(MidiMessage::allNotesOff(cur_msg.getChannel()),
                                        sample_pos);
                DBG("AllNotesOff Event added to buffer because of change. Channel: "
                    << cur_msg.getChannel() << " sample_pos: " << sample_pos);
                state_changed_ = false;
            }
            if (*is_on_ > FLT_MIN)
            {
                auto orig_nn = cur_msg.getNoteNumber();
                auto new_nn = getNegHarmNn(orig_nn);
                DBG("Transformed ["
                    << orig_nn << "] "
                    << MidiMessage::getMidiNoteName(orig_nn, true, true, 3) << " to ["
                    << new_nn << "] "
                    << MidiMessage::getMidiNoteName(new_nn, true, true, 3));
                cur_msg.setNoteNumber(new_nn);
            }
        }
        p_midi_buffer_.addEvent(cur_msg, sample_pos);
    }
    midi_messages.swapWith(p_midi_buffer_);
}

void
MidiProcessor::parameterChanged(const String &parameter_id,
                                float new_value)
{
    DBG("parameterChanged Event: - parameter_id: " << parameter_id << " new_value: " << new_value);
    state_changed_ = true;
}

int
MidiProcessor::getNegHarmNn(int nn)
{
    DBG("getNegHarmNn called, nn: " << nn << " key: " << *cur_key_);
    MidiMessage::getMidiNoteName(nn, false, true, 4);

    //  return 2*tonic + 7 - nn;
    return nn;
}
