/*
  ==============================================================================

    ToNegativeHarmonyValueTree.cpp
    Created: 27 Dec 2019 4:51:59pm
    Author:  phili

  ==============================================================================
*/

#include "ToNegativeHarmonyValueTree.h"

ToNegativeHarmonyValueTree::ToNegativeHarmonyValueTree(ToNegativeHarmonyProcessor& p) : processor_(p), processor_value_tree_(
  processor_, &undo_manager_, value_tree_name, 
  {
    std::make_unique<AudioParameterBool>(is_plugin_active.getCharPointer(), "is to negative Harmony active", false),
    std::make_unique<AudioParameterInt>(active_key.getCharPointer(), "key on which transformation is based", 0, 127, 60)
  })
{
}

ToNegativeHarmonyValueTree::~ToNegativeHarmonyValueTree()
= default;

void ToNegativeHarmonyValueTree::valueTreePropertyChanged(ValueTree& tree_whose_property_has_changed, const Identifier& property)
{
}

void ToNegativeHarmonyValueTree::valueTreeChildAdded(ValueTree& parent_tree, ValueTree& child_which_has_been_added)
{
}

void ToNegativeHarmonyValueTree::valueTreeChildRemoved(ValueTree& parent_tree, ValueTree& child_which_has_been_removed,
  int index_from_which_child_was_removed)
{
}

void ToNegativeHarmonyValueTree::valueTreeChildOrderChanged(ValueTree& parent_tree_whose_children_have_moved, int old_index,
  int new_index)
{
}

void ToNegativeHarmonyValueTree::valueTreeParentChanged(ValueTree& tree_whose_parent_has_changed)
{
}

void ToNegativeHarmonyValueTree::valueTreeRedirected(ValueTree& tree_which_has_been_changed)
{
}
