/*
  ==============================================================================

    PluginValueTree.cpp
    Created: 27 Dec 2019 4:51:59pm
    Author:  phili

  ==============================================================================
*/

#include "PluginValueTree.h"

PluginValueTree::PluginValueTree(ToNegativeHarmonyProcessor& p) : processor_(p),
processor_value_tree_(p, &undo_manager_, value_tree_name_, 
  {std::make_unique<AudioParameterBool>("is_plugin_active", "is to negative Harmony active", false),
  std::make_unique<AudioParameterInt>("active_Key", "key on which transformation is based", 0, 127, 60)})
{
}

PluginValueTree::~PluginValueTree()
{
}

void PluginValueTree::createToNegativeHarmonyDefaultTree()
{
}

void PluginValueTree::changeListenerCallback(ChangeBroadcaster* source)
{
}

void PluginValueTree::valueChanged(Value& value)
{
}
