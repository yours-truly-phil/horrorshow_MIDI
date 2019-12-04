/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Horrorshow_midiAudioProcessorEditor::Horrorshow_midiAudioProcessorEditor (Horrorshow_midiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	setSize(600, 400);

	addAndMakeVisible(pluginTitleLabel);
	addAndMakeVisible(midiNotesDownInfoTable);
	addAndMakeVisible(midiEventsLists);

	setResizable(true, true);
}

Horrorshow_midiAudioProcessorEditor::~Horrorshow_midiAudioProcessorEditor()
{
}

//==============================================================================
void Horrorshow_midiAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void Horrorshow_midiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	auto titleHeight = 60;
	auto eventListWidth = 100;
	pluginTitleLabel.setBounds(0, 0, getWidth(), titleHeight);
	pluginTitleLabel.setJustificationType(Justification::topRight);
	midiEventsLists.setBounds(0, titleHeight, eventListWidth, getHeight());
	midiNotesDownInfoTable.setBounds(eventListWidth, titleHeight, getWidth() - eventListWidth, getHeight());
}
