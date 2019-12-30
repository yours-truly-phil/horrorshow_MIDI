/*
  ==============================================================================

    ToNegativeHarmonyController.cpp
    Created: 27 Dec 2019 4:51:59pm
    Author:  phili

  ==============================================================================
*/

#include "ToNegativeHarmonyController.h"

ToNegativeHarmonyController::ToNegativeHarmonyController()
{
  initValueTree();
  DBG(value_tree_.toXmlString());
}

ToNegativeHarmonyController::~ToNegativeHarmonyController()
{
}

ValueTree ToNegativeHarmonyController::initValueTree()
{
  value_tree_ = ValueTree("plugin_value_tree");
  value_tree_.setProperty(is_plugin_active_id_, "is_plugin_active_param_name", false);
  return value_tree_;
}

void ToNegativeHarmonyController::switchIsToNegativeHarmonyActive()
{
  DBG("switchToNegativeHarmonyActive Event!");
  auto property = value_tree_.getProperty(is_plugin_active_id_);
  DBG(property.toString());
}
