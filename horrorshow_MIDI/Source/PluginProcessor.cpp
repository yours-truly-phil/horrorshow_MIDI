/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"

#include "PluginEditor.h"

//==============================================================================
ToNegativeHarmonyProcessor::ToNegativeHarmonyProcessor() :
#ifndef JucePlugin_PreferredChannelConfigurations
     AudioProcessor(BusesProperties()
    #if ! JucePlugin_IsMidiEffect
    #if ! JucePlugin_IsSynth
        .withInput("Input", AudioChannelSet::stereo(), true)
    #endif
        .withOutput("Output", AudioChannelSet::stereo(), true)
    #endif
    ),
#endif
apvts_(*this, nullptr, "PARAMETERS",
             createParameters())//, midi_processor_(apvts_)
{
}

ToNegativeHarmonyProcessor::~ToNegativeHarmonyProcessor()
= default;

//==============================================================================
const String ToNegativeHarmonyProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ToNegativeHarmonyProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool ToNegativeHarmonyProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool ToNegativeHarmonyProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double ToNegativeHarmonyProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ToNegativeHarmonyProcessor::getNumPrograms()
{
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int ToNegativeHarmonyProcessor::getCurrentProgram()
{
    return 0;
}

void ToNegativeHarmonyProcessor::setCurrentProgram(int index)
{
}

const String ToNegativeHarmonyProcessor::getProgramName(int index)
{
    return {};
}

void ToNegativeHarmonyProcessor::changeProgramName(int index, const String & new_name)
{
}

//==============================================================================
void ToNegativeHarmonyProcessor::prepareToPlay(double sample_rate, int samples_per_block)
{
    // Use this method as the place to do any pre-playback
    // initialization that you need.
}

void ToNegativeHarmonyProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ToNegativeHarmonyProcessor::isBusesLayoutSupported(const BusesLayout & layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused(layouts);
    return true; // TODO: since this is at heart a MIDI effect, at first glance it looks like sth looked at long enough
#else
    // Validate the bus layout here.
        // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif
    return true;
#endif
}
#endif

void ToNegativeHarmonyProcessor::processBlock(AudioBuffer<float> & buffer, MidiBuffer & midi_messages)
{
    ScopedNoDenormals no_denormals;
    const auto kTotalNumInputChannels = getTotalNumInputChannels();
    const auto kTotalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = kTotalNumInputChannels; i < kTotalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can Process the samples with the channels
    // interleaved by keeping the same state.
    //for (auto channel = 0; channel < totalNumInputChannels; ++channel)
    //{
    //    auto* channelData = buffer.getWritePointer(channel);

    //    // -> do something to the data...
    //}

    midi_processor_.processMidiMsgsBlock(midi_messages);
}

//==============================================================================
bool ToNegativeHarmonyProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ToNegativeHarmonyProcessor::createEditor()
{
    return new ToNegativeHarmonyEditor(*this, apvts_);
}

//==============================================================================
void ToNegativeHarmonyProcessor::getStateInformation(MemoryBlock & dest_data)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    const auto kState = apvts_.copyState();
    const auto kXml(kState.createXml());
    copyXmlToBinary(*kXml, dest_data);
}

void ToNegativeHarmonyProcessor::setStateInformation(const void* data, int size_in_bytes)
{
    // You should use this method to restore your parameters from this memory block.
    // getStateInformation() creates its content.
    const auto kXmlState(getXmlFromBinary(data, size_in_bytes));

    if (kXmlState != nullptr && kXmlState->hasTagName(apvts_.state.getType()))
        apvts_.replaceState(ValueTree::fromXml(*kXmlState));
}

//==============================================================================
// This creates new instances of the plugin (One at a time though, no? y the plural?
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ToNegativeHarmonyProcessor();
}


AudioProcessorValueTreeState::ParameterLayout ToNegativeHarmonyProcessor::createParameters() const
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;

    params.push_back(std::make_unique<AudioParameterBool>(kIdIsProcessingActive, "is processing active", false));

    params.push_back(std::make_unique<AudioParameterInt>(kIdTonicNn, "Note number of active tonic", 0, 127, 60, "Note Number active tonic Label text"));

    params.push_back(std::make_unique<AudioParameterInt>(kIdMinMidiNoteNumber, "Smallest Midi Note Number", 0, 127, 24));
    params.push_back(std::make_unique<AudioParameterInt>(kIdMaxMidiNoteNumber, "Largest Midi Note Number", 0, 127, 127));
    params.push_back(std::make_unique<AudioParameterInt>(kIdMidiNNoPianoMin, "Smallest Playable Midi Note Number", 0, 127, 21));
    params.push_back(std::make_unique<AudioParameterInt>(kIdMidiNNoPianoMax, "Largest Playable Midi Note Number", 0, 127, 108));

    return { params.begin(), params.end() };
}