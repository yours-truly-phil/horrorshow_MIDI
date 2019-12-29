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

class ToNegativeHarmonyValueTree final : private ValueTree::Listener
{
public:
  explicit ToNegativeHarmonyValueTree(ToNegativeHarmonyProcessor& p);
  ~ToNegativeHarmonyValueTree();

  void valueTreePropertyChanged(ValueTree& tree_whose_property_has_changed, const Identifier& property) override;
  void valueTreeChildAdded(ValueTree& parent_tree, ValueTree& child_which_has_been_added) override;
  void valueTreeChildRemoved(ValueTree& parent_tree, ValueTree& child_which_has_been_removed,
    int index_from_which_child_was_removed) override;
  void valueTreeChildOrderChanged(ValueTree& parent_tree_whose_children_have_moved, int old_index, int new_index) override;
  void valueTreeParentChanged(ValueTree& tree_whose_parent_has_changed) override;
  void valueTreeRedirected(ValueTree& tree_which_has_been_changed) override;

private:
  ToNegativeHarmonyProcessor& processor_;

  UndoManager undo_manager_ {30000, 30};
  AudioProcessorValueTreeState processor_value_tree_;
  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToNegativeHarmonyValueTree)
};
