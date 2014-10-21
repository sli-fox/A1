#include <Cat.h>

/**  @brief The Cat constructor.
  *  Calls initializeCritter() to set attributes of the 
  *  Cat object
  */
Cat::Cat() {
  initializeCritter();
}

/**  Initialization specific to a Cat object
  */
void Cat::initializeCritter() {
  critter_type = "Cat";

  // Attributes for a cat
  hit_points = 10;
  steal_strength = 4;
  player_reward = 5;
  speed = 2.0f;
  level = 1;
}
