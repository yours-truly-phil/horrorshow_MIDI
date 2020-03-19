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

constexpr auto kIdMinMidiNoteNumber     = "id_min_midi_note_number";
constexpr auto kIdMaxMidiNoteNumber     = "id_max_midi_note_number";
constexpr auto kIdMidiNNoPianoMin       = "id_min_piano_midi_note_number";
constexpr auto kIdMidiNNoPianoMax       = "id_max_piano_midi_note_number";

//==============================================================================
/**
*/
class ToNegativeHarmonyProcessor : public AudioProcessor
{
public:
    //==============================================================================
    ToNegativeHarmonyProcessor();
    ~ToNegativeHarmonyProcessor() override;

    //==============================================================================
    void prepareToPlay(double sample_rate, int samples_per_block) override;
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
    void changeProgramName(int index, const String& new_name) override;

    //==============================================================================
    void getStateInformation(MemoryBlock& dest_data) override;
    void setStateInformation(const void* data, int size_in_bytes) override;

private:
    //==============================================================================
    AudioProcessorValueTreeState apvts_;

    MidiProcessor midi_processor_ {apvts_};

    AudioProcessorValueTreeState::ParameterLayout createParameters() const;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyProcessor)
};
