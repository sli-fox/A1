#include <Critter.h>

int Critter::getHitPoints() const {
  return hit_points;
}
void Critter::removeHitPoints(int points){
  this->hit_points -= points;
}
int Critter::getStealStrength() const {
  return steal_strength;
} 
int Critter::getPlayerReward() const {
  return player_reward;
} 
float Critter::getSpeed() const {
  return speed;
} 
int Critter::getLevel() const {
  return level;
}
std::string Critter::getType() const {
  return critter_type;
}

std::string Critter::getPosition() const {
  std::string output = "(" + std::to_string(row) + "," + std::to_string(col) + ")"; 
  return output;
}

/**  This function goes through every cell in the map, looking for 
 *   the next path or exit cell. The search begins at the critter's
 *   current position, which is passed in. If the next path cell is found,
 *   the Critter's position (row and column) is updated to that cell. If the 
 *   the exit is reached, the critter steals coins from the player.
 */
void Critter::chooseNextPathCell(Map& map, int current_row, int current_col, Player& player) {
  for (int i = current_row - 1; i < map.map_size; ++i) {
    for (int j = current_col; j < map.map_size; ++j) { 
      if (map.map[i][j].type == Map::PATH) {
        this->row = i + 1; 
        this->col = j + 1;
        return;
      }
      if (map.map[i][j].type == Map::EXIT) {
        this->row = i + 1;  // Doesn't go past the grid size
        this->col = j + 1;  // Doesn't go past the grid size
        player.removeCoins(this->getStealStrength());
        return;
      }
    }
  }
}

void Critter::takeDamage(int damage) {
  //No need to take health from dead Critters!
  if (this->getHitPoints() <= 0) {
    return;
  } else {
    this->removeHitPoints(damage); 
  }
}
