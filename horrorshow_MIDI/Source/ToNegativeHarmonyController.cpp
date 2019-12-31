/*
/*
  ==============================================================================

    ToNegativeHarmonyController.cpp
    Created: 27 Dec 2019 4:51:59pm
    Author:  phili

  ==============================================================================
#1#

#include "ToNegativeHarmonyController.h"

ToNegativeHarmonyController::ToNegativeHarmonyController()
{
  initValueTree();
}

ToNegativeHarmonyController::~ToNegativeHarmonyController()
= default;

ValueTree ToNegativeHarmonyController::initValueTree()
{
  value_tree_ = ValueTree("plugin_value_tree");
  value_tree_.setProperty(id_is_on_neg_harm_conversion_, false, nullptr);
  value_tree_.setProperty(id_active_tonic_note_number_, 60, nullptr);
  return value_tree_;
}

void ToNegativeHarmonyController::switchIsToNegativeHarmonyActive()
{
  DBG("switchToNegativeHarmonyActive Event!");
  bool is_on = value_tree_[id_is_on_neg_harm_conversion_];
  DBG("Property value is: " << int(is_on));
  is_on = !is_on;
  DBG("New Property value is: " << int(is_on));
  value_tree_.setProperty(id_is_on_neg_harm_conversion_, false, nullptr);
}

//ValueTree& ToNegativeHarmonyController::getValueTree()
//{
//  return parameters_;
//}
*/
