/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiProcessor.h"
#include "ToNegativeHarmonyController.h"

//==============================================================================
/**
*/
class ToNegativeHarmonyProcessor : public AudioProcessor
{
public:
    //==============================================================================
    ToNegativeHarmonyProcessor();
    ~ToNegativeHarmonyProcessor();

    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif

    void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const String getProgramName(int index) override;
    void changeProgramName(int index, const String& newName) override;

    //==============================================================================
    void getStateInformation(MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    //bool is_midi_convertion_on = true;

private:
    //std::unique_ptr<ValueWithDefault> is_neg_harm_processing_active_;
    //ValueWithDefault is_neg_harm_processing_active {audio_processor_value_tree_state_, new Identifier("is_neg_harm_processing_active"), nullptr}
    MidiProcessor midi_processor_;
    ToNegativeHarmonyController controller_;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyProcessor)
};
