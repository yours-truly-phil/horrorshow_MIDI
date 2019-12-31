/*
/*
  ==============================================================================

    ToNegativeHarmonyController.h
    Created: 27 Dec 2019 4:09:26pm
    Author:  phili

  ==============================================================================
#1#

#pragma once


#include "ToNegativeHarmonyController.h"

#include "JuceHeader.h"



class ToNegativeHarmonyController : ValueTree::Listener
{
  const Identifier id_is_on_neg_harm_conversion_ = "is_on_neg_harm_conversion";
  const Identifier id_active_tonic_note_number_ = "active_tonic_note_number";

public:
  ToNegativeHarmonyController();
  ~ToNegativeHarmonyController();

  void switchIsToNegativeHarmonyActive();

  //ValueTree& getValueTree();
private:
  ValueTree initValueTree();

  //ToNegativeHarmonyProcessor& processor_;
  ValueTree value_tree_;
  //std::unique_ptr<AudioProcessorValueTreeState> root_item_;
  //UndoManager undo_manager_;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyController)
};
*/
