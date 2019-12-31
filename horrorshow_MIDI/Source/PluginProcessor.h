/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiProcessor.h"

constexpr auto kIdTonicNn = "id_tonic_nn";
constexpr auto kIdPluginState = "id_plugin_state";

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
    AudioProcessorValueTreeState::ParameterLayout create_parameters() const;

    //AudioParameterChoice* p_plugin_state_{ new AudioParameterChoice(kIdPluginState, "Plugin State", StringArray{ "ON", "BYPASS" }, 0) };
    //AudioParameterInt* p_tonic_note_no_{ new AudioParameterInt(kIdTonicNn, "Note number of active tonic", 0, 127, 60)};

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyProcessor)
};
