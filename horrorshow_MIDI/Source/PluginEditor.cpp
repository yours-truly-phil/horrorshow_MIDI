/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Horrorshow_midiAudioProcessorEditor::Horrorshow_midiAudioProcessorEditor(Horrorshow_midiAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(600, 400);

    addAndMakeVisible(plugin_ui_header_);
    addAndMakeVisible(midi_active_now_);
    addAndMakeVisible(midi_events_);

    setResizable(true, true);
}

Horrorshow_midiAudioProcessorEditor::~Horrorshow_midiAudioProcessorEditor()
{
}

//==============================================================================
void Horrorshow_midiAudioProcessorEditor::paint(Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void Horrorshow_midiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto title_height = 60;
    auto event_list_width = 100;
    plugin_ui_header_.setBounds(0, 0, getWidth(), title_height);
    plugin_ui_header_.setJustificationType(Justification::topRight);
    midi_events_.setBounds(0, title_height, event_list_width, getHeight());
    midi_active_now_.setBounds(event_list_width, title_height, getWidth() - event_list_width, getHeight());
}
