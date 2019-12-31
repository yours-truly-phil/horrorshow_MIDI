/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"

#include "PluginProcessor.h"

//==============================================================================
ToNegativeHarmonyEditor::ToNegativeHarmonyEditor(ToNegativeHarmonyProcessor& p, AudioProcessorValueTreeState& v)
    : AudioProcessorEditor(&p), processor_(p), value_tree_state_(v)
{
    midi_keyboard_state_.addListener(this);

    setSize(600, 200);

    addAndMakeVisible(midi_keyboard_component_);
    addAndMakeVisible(plugin_ui_header_);
    addAndMakeVisible(power_on_button_);
    power_on_button_attachment_.reset(new ButtonAttachment(value_tree_state_, ID_PLUGIN_STATE, power_on_button_));

}

ToNegativeHarmonyEditor::~ToNegativeHarmonyEditor()
{
    midi_keyboard_state_.removeListener(this);
}

//==============================================================================
void ToNegativeHarmonyEditor::handleNoteOn(MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity)
{
    
}

void ToNegativeHarmonyEditor::handleNoteOff(MidiKeyboardState* source, int midiChannel, int midiNoteNumber, float velocity)
{

}


void ToNegativeHarmonyEditor::paint(Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void ToNegativeHarmonyEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    power_on_button_.setBounds(0, 0, getWidth(), 100);
    power_on_button_.changeWidthToFitText();
    midi_keyboard_component_.setBounds(0, 100, 600, 100);

    plugin_ui_header_.setBounds(0, 0, getWidth(), 100);
    plugin_ui_header_.setJustificationType(Justification::topRight);
}
