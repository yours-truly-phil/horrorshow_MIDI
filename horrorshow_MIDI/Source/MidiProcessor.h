/*
  ==============================================================================

    MidiProcessor.h
    Created: 27 Dec 2019 2:35:46pm
    Author:  phili

  ==============================================================================
*/

#pragma once

#include <atomic>

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include <valarray>

// put some music theory step by step into this, if in mood
#define ACCIDENTIALS {{ 0, { "", "♮" } },{ 1, { "#", "♯", "sharp" }},{ -1, { "b", "♭", "flat" } },{ 2, { "x", "double-sharp" } },{ -2, { "𝄫", "double-flat" } }}
#define NOTE_LETTERS {{0,C}, {2,D}, {4,E}, {5,F}, {7,G}, {9,A}, {11,B}}
constexpr auto octave = 12;

class MidiProcessor
{
public:
  explicit MidiProcessor(AudioProcessorValueTreeState& vts);
  ~MidiProcessor();

  void process(MidiBuffer& midi_messages);

  // TODO: lol let's do TDD from now on

  //static MidiMessage& transform(MidiMessage& message, const int dist)
  //{
  //  auto move_me = message.getNoteNumber();
  //  auto i = (move_me + dist);
  //  auto x = float(i) / 128.0f;
  //  auto rem = div(i,octave);
  //  if(x < *p_nn_low_bound_)
  //    x = *p_nn_low_bound_ + (octave - rem.rem) / 128.0f;
  //  if(x > *p_nn_up_bound_)
  //    x = *p_nn_up_bound_ - (octave + rem.rem) / 128.0f;
  //  move_me = roundFloatToInt(x * 128.0f);
  //  message.setNoteNumber(move_me);
  //  return message;
  //}

  //bool clip(const int* n)
  //{
  //  //juce::FloatVectorOperations::copyWithMultiply(p_nn_bounds_denrmlzd_->front(),p_nn_bounds_->front(),127,2);
  //  juce::FloatVectorOperations::convertFixedToFloat(p_nn_, n, 1.0f/128.0f, 1);
  //  //return (p_nn_low_bound_ <= n && n <= p_nn_low_bound_)
  //  juce::FloatVectorOperations::clip(p_nn_, p_nn_, p_nn_low_bound_->operator float(), p_nn_up_bound_->operator float(), 1);
  //}

private:
  MidiBuffer p_midi_buffer_;

  AudioProcessorValueTreeState& apvts_;

  float* p_nn_;
  std::atomic<float>*   p_nn_up_bound_;
  std::atomic<float>*   p_nn_low_bound_;
  std::vector<float*>*    p_nn_bounds_;
  std::vector<float*>*    p_nn_bounds_denrmlzd_;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiProcessor)
};
