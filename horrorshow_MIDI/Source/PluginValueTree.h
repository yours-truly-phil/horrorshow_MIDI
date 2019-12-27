/*
  ==============================================================================

    PluginValueTree.h
    Created: 27 Dec 2019 4:09:26pm
    Author:  phili

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginValueTree.h"
#include "PluginProcessor.h"

class PluginValueTree : private ValueTree::Listener, private ChangeListener, private Value::Listener
{
public:
  PluginValueTree(ToNegativeHarmonyProcessor& p);
  ~PluginValueTree();

private:
  void changeListenerCallback(ChangeBroadcaster* source) override;
  void valueChanged(Value& value) override;

  void createToNegativeHarmonyDefaultTree();
  Identifier value_tree_name_ { "plugin_value_tree" };
  UndoManager undo_manager_ {30000, 30};
  ToNegativeHarmonyProcessor& processor_;
  AudioProcessorValueTreeState processor_value_tree_;


};
