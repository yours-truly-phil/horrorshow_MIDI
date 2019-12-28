/*
  ==============================================================================

    ToNegativeHarmonyValueTree.h
    Created: 27 Dec 2019 4:09:26pm
    Author:  phili

  ==============================================================================
*/

#pragma once


#include "ToNegativeHarmonyValueTree.h"

#include "JuceHeader.h"
#include "PluginProcessor.h"

static Identifier value_tree_name =  "plugin_value_tree";
static Identifier is_plugin_active = "active_Key";
static Identifier active_key = "active_Key";

class ToNegativeHarmonyValueTree final : ValueTree::Listener
{
public:
  explicit ToNegativeHarmonyValueTree(ToNegativeHarmonyProcessor& p);
  ~ToNegativeHarmonyValueTree();

  void valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property) override;
  void valueTreeChildAdded(ValueTree& parentTree, ValueTree& childWhichHasBeenAdded) override;
  void valueTreeChildRemoved(ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved,
    int indexFromWhichChildWasRemoved) override;
  void valueTreeChildOrderChanged(ValueTree& parentTreeWhoseChildrenHaveMoved, int oldIndex, int newIndex) override;
  void valueTreeParentChanged(ValueTree& treeWhoseParentHasChanged) override;
  void valueTreeRedirected(ValueTree& treeWhichHasBeenChanged) override;

private:
  UndoManager undo_manager_ {30000, 30};
  AudioProcessorValueTreeState processor_value_tree_;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyValueTree)
};
