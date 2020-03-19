/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"

#include "PluginProcessor.h"

//==============================================================================
ToNegativeHarmonyEditor::ToNegativeHarmonyEditor(ToNegativeHarmonyProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), processor_(p), apvts_(vts)
{
    state_midi_keyboard_.addListener(this);
    
    c_power_on_button_attachment_ = std::make_unique<ButtonAttachment>(apvts_, kIdIsProcessingActive, c_power_on_button_);
    c_tonic_note_no_slider_attachment_ = std::make_unique<SliderAttachment>(apvts_, kIdTonicNn, c_tonic_note_no_slider_);
    c_choice_box_attachment_ = std::make_unique<ComboBoxAttachment>(apvts_, kIdIsProcessingActive, c_choice_box_);

    addAndMakeVisible(c_midi_keyboard_);

    addAndMakeVisible(c_power_on_button_);
    addAndMakeVisible(c_tonic_note_no_slider_);
    
    c_choice_box_.addItem("choice box addItem with id 2", 2);
    c_choice_box_.addItem("choice box addItem with id 3", 3);
    c_choice_box_.addItem("choice box addItem with id 4", 4);
    addAndMakeVisible(c_choice_box_);

    addAndMakeVisible(c_plugin_ui_header_);

    setSize(PLUGIN_WIDTH, PLUGIN_HEIGHT);
}

ToNegativeHarmonyEditor::~ToNegativeHarmonyEditor()
{
    state_midi_keyboard_.removeListener(this);
}

//==============================================================================
void ToNegativeHarmonyEditor::handleNoteOn(MidiKeyboardState* source, int midi_channel, int midi_note_number, float velocity)
{
    
}

void ToNegativeHarmonyEditor::handleNoteOff(MidiKeyboardState* source, int midi_channel, int midi_note_number, float velocity)
{

}


void ToNegativeHarmonyEditor::paint(Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void ToNegativeHarmonyEditor::resized()
{
    auto bounds = getLocalBounds();

    c_midi_keyboard_.setBounds(bounds.removeFromBottom(200));

    c_power_on_button_.setBounds(bounds.removeFromLeft(200));

    c_tonic_note_no_slider_.setBounds(bounds.removeFromLeft(200));

    c_choice_box_.setBounds(bounds.removeFromLeft(200));

    c_plugin_ui_header_.setBounds(bounds.removeFromRight(200));
    c_plugin_ui_header_.setJustificationType(Justification::topRight);
}
