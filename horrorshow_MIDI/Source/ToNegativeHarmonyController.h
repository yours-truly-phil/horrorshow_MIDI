/*
  ==============================================================================

    ToNegativeHarmonyController.h
    Created: 27 Dec 2019 4:09:26pm
    Author:  phili

  ==============================================================================
*/

#pragma once


#include "ToNegativeHarmonyController.h"

#include "JuceHeader.h"



class ToNegativeHarmonyController : ValueTree::Listener
{

  const Identifier value_tree_id_ =  "plugin_value_tree";
  const Identifier is_plugin_active_ = "active_Key";
  const Identifier active_key_ = "active_Key";

public:
  ToNegativeHarmonyController();
  ~ToNegativeHarmonyController();

  void switchIsToNegativeHarmonyActive();

private:
  //ToNegativeHarmonyProcessor& processor_;
  ValueTree value_tree_ {value_tree_id_};
  //std::unique_ptr<AudioProcessorValueTreeState> root_item_;
  //UndoManager undo_manager_;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyController)
};
