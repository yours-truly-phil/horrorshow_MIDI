/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Horrorshow_midiAudioProcessorEditor : public AudioProcessorEditor
{
public:
    Horrorshow_midiAudioProcessorEditor(Horrorshow_midiAudioProcessor&);
    ~Horrorshow_midiAudioProcessorEditor();

    //==============================================================================
    void paint(Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Horrorshow_midiAudioProcessor& processor;

    TableListBox midi_active_now_;
    ListBox midi_events_;
    Label plugin_ui_header_{"label_plugin_header", processor.getName()};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Horrorshow_midiAudioProcessorEditor)
};
