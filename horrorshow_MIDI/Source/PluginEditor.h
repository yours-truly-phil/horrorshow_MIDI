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
class ToNegativeHarmonyEditor : public AudioProcessorEditor, private Button::Listener, private MidiKeyboardStateListener
{
public:
    ToNegativeHarmonyEditor(ToNegativeHarmonyProcessor&);
    ~ToNegativeHarmonyEditor();

    //==============================================================================
    void paint(Graphics&) override;
    void resized() override;

private:
    void buttonClicked(Button*) override;

    void handleNoteOn(MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity) override;
    void handleNoteOff(MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ToNegativeHarmonyProcessor& processor;

    MidiKeyboardState midi_keyboard_state_;
    MidiKeyboardComponent midi_keyboard_component_;
    ToggleButton toggle_neg_harm_button_ {"to negative Harmony"};

    //TableListBox midi_active_now_;
    //ListBox midi_events_;
    Label plugin_ui_header_{"label_plugin_header", processor.getName()};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyEditor)
};
