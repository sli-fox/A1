#include <Dog.h>

/**  @brief The Dog constructor.
  *  Calls initializeCritter() to set attributes of the 
  *  Dog object
  */
Dog::Dog() {
  initializeCritter();
}

/**  Initialization specific to a Cat object
  */
void Dog::initializeCritter() {
  this->critter_type = "Dog";

  // Attributes for a cat
  this->hit_points = 15;
  this->steal_strength = 6;
  this->player_reward = 8;
  this->speed = 2.5f;
  this->level = 2;
}
