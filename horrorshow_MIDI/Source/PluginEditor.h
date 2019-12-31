/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

//==============================================================================
/**
*/
class ToNegativeHarmonyEditor : public AudioProcessorEditor, private MidiKeyboardStateListener
{
public:
    ToNegativeHarmonyEditor(ToNegativeHarmonyProcessor&);
    ~ToNegativeHarmonyEditor();

    //==============================================================================
    void paint(Graphics&) override;
    void resized() override;

private:
    void handleNoteOn(MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity) override;
    void handleNoteOff(MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ToNegativeHarmonyProcessor& processor_;
    //AudioProcessorValueTreeState& value_tree_state_;
    
    MidiKeyboardState state_midi_keyboard_;

    MidiKeyboardComponent   c_midi_keyboard_        {state_midi_keyboard_, MidiKeyboardComponent::horizontalKeyboard};
    ToggleButton            c_power_on_button_      {"to negative Harmony"};
    Slider                  c_tonic_note_no_slider_ { Slider::SliderStyle::LinearHorizontal, Slider::TextEntryBoxPosition::TextBoxBelow };
    ComboBox                c_choice_box_           {"plugin_states_choice_box"};
    Label                   c_plugin_ui_header_     {"label_plugin_header", processor_.getName()};

    std::unique_ptr<ButtonAttachment>   act_power_on_button_;
    std::unique_ptr<SliderAttachment>   act_tonic_note_no_slider_;
    std::unique_ptr<ComboBoxAttachment> act_choice_box_;

    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyEditor)
};
