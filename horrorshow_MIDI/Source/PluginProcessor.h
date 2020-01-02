/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiProcessor.h"

constexpr auto kIdTonicNn               = "id_tonic_nn";
constexpr auto kIdIsProcessingActive    = "id_is_processing_active";

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
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
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

    
private:
    //==============================================================================
    MidiProcessor midi_processor_;

    AudioProcessorValueTreeState value_tree_state_;

    std::atomic<float>* is_on_;
    std::atomic<float>* cur_tonic_;

    AudioProcessorValueTreeState::ParameterLayout create_parameters() const;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyProcessor)
};
