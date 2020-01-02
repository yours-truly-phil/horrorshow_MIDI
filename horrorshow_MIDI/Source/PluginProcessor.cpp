/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"

#include "PluginEditor.h"

//==============================================================================
ToNegativeHarmonyProcessor::ToNegativeHarmonyProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
#endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                       ) ,
#else
    :
#endif
value_tree_state_(*this, nullptr, "PARAMETERS", create_parameters())
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

void ToNegativeHarmonyProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void ToNegativeHarmonyProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialization that you need..
}

void ToNegativeHarmonyProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ToNegativeHarmonyProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
#else
// This is the place where you check if the layout is supported.
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

void ToNegativeHarmonyProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals no_denormals;
    const auto total_num_input_channels = getTotalNumInputChannels();
    const auto total_num_output_channels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = total_num_input_channels; i < total_num_output_channels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    //for (auto channel = 0; channel < totalNumInputChannels; ++channel)
    //{
    //    auto* channelData = buffer.getWritePointer(channel);

    //    // ..do something to the data...
    //}

    midi_processor_.process(midiMessages);
}

//==============================================================================
bool ToNegativeHarmonyProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ToNegativeHarmonyProcessor::createEditor()
{
    return new ToNegativeHarmonyEditor(*this, value_tree_state_);
}

//==============================================================================
void ToNegativeHarmonyProcessor::getStateInformation(MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    //
    // TODO
    //std::unique_ptr<XmlElement> xml(new XmlElement(getName()));
    //xml->setAttribute(kIdPluginState, p_plugin_state_->getCurrentChoiceName());
    //xml->setAttribute(kIdTonicNn, *p_tonic_note_no_);
    //copyXmlToBinary(*xml, destData);
}

void ToNegativeHarmonyProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    //const auto xml_state(getXmlFromBinary(data, sizeInBytes));
    //
    // TODO
    //if(xml_state != nullptr)
    //{
    //    if(xml_state->hasTagName(getName()))
    //    {
    //        *p_plugin_state_ = xml_state->getIntAttribute(kIdPluginState);
    //        *p_tonic_note_no_ = xml_state->getIntAttribute(kIdTonicNn);
    //    }
    //}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ToNegativeHarmonyProcessor();
}

AudioProcessorValueTreeState::ParameterLayout ToNegativeHarmonyProcessor::create_parameters() const
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;
    params.push_back(std::make_unique<AudioParameterChoice> (kIdPluginState, "Plugin State", StringArray("ON", "BYPASS"), 0));
    params.push_back(std::make_unique<AudioParameterInt> (kIdTonicNn, "Note number of active tonic", 0, 127, 60));
    return { params.begin(), params.end() };
}
