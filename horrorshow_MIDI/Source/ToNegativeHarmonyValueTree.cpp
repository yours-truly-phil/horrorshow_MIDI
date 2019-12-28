/*
  ==============================================================================

    ToNegativeHarmonyValueTree.cpp
    Created: 27 Dec 2019 4:51:59pm
    Author:  phili

  ==============================================================================
*/

#include "ToNegativeHarmonyValueTree.h"

ToNegativeHarmonyValueTree::ToNegativeHarmonyValueTree(ToNegativeHarmonyProcessor& p) : processor_value_tree_(
  p, &undo_manager_, value_tree_name, 
  {
    std::make_unique<AudioParameterBool>(is_plugin_active.getCharPointer(), "is to negative Harmony active", false),
    std::make_unique<AudioParameterInt>(active_key.getCharPointer(), "key on which transformation is based", 0, 127, 60)
  })
{
}

ToNegativeHarmonyValueTree::~ToNegativeHarmonyValueTree()
{
}

void ToNegativeHarmonyValueTree::valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
}

void ToNegativeHarmonyValueTree::valueTreeChildAdded(ValueTree& parentTree, ValueTree& childWhichHasBeenAdded)
{
}

void ToNegativeHarmonyValueTree::valueTreeChildRemoved(ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved,
  int indexFromWhichChildWasRemoved)
{
}

void ToNegativeHarmonyValueTree::valueTreeChildOrderChanged(ValueTree& parentTreeWhoseChildrenHaveMoved, int oldIndex,
  int newIndex)
{
}

void ToNegativeHarmonyValueTree::valueTreeParentChanged(ValueTree& treeWhoseParentHasChanged)
{
}

void ToNegativeHarmonyValueTree::valueTreeRedirected(ValueTree& treeWhichHasBeenChanged)
{
}
