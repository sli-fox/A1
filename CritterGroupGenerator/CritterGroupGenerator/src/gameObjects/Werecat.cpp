#include <Werecat.h>

/**  @brief The Werecat constructor.
  *  Calls initializeCritter() to set attributes of the 
  *  Werecat object
  */
Werecat::Werecat() {
  initializeCritter();
}

/**  Initialization specific to a Werecat object
  */
void Werecat::initializeCritter() {
  this->critter_type = "Werecat";

  // Attributes for a cat
  this->hit_points = 20;
  this->steal_strength = 8;
  this->player_reward = 10;
  this->speed = 3.0f;
  this->level = 3;
}
