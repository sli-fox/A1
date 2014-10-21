#include <Werewolf.h>

/**  @brief The Werecat constructor.
  *  Calls initializeCritter() to set attributes of the 
  *  Werecat object
  */
Werewolf::Werewolf() {
  initializeCritter();
}

/**  Initialization specific to a Werewolf object
  */
void Werewolf::initializeCritter() {
  this->critter_type = "Werewolf";

  // Attributes for a cat
  this->hit_points = 40;
  this->steal_strength = 12;
  this->player_reward = 15;
  this->speed = 4.0f;
  this->level = 4;
}
