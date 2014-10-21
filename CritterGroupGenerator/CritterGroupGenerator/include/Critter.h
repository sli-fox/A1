/** @file Critter.h
 *  @brief Representation of critter object.
 *
 *  This is the abstract representation of the critter object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <iostream>
#include <string>
#include <Map.h>
#include <Player.h>

/** @brief Abstract base class of all Critters
 *  Critter defines the attributes, accessors, and update function
 *  for its subclass instances. 
 */
class Critter {
  public:

    Critter() {};
    virtual ~Critter() {};
    int row;
    int col;

    int getHitPoints() const; 
    void removeHitPoints(int points);
    int getStealStrength() const; 
    int getPlayerReward() const; 
    float getSpeed() const; 
    int getLevel() const;
    std::string getType() const;
    std::string getPosition() const;

   /** @brief Picks the next path cell to go to.
    *  @param map Map reference.
    *  @param current_row Current row of Critter position.
    *  @param current_col Current column of Critter position.
    *  @return Void.
    */
    void chooseNextPathCell(Map& map, int current_row, int current_col, Player& player);

    /** @brief Handles the damage taken by a Critter in range of a Tower.
    *  @param damage Int representing the amount of health lost per hit.
    *  @return Void.
    */
    void takeDamage(int damage);

    /** @brief Overloaded cout operator to print out Critters.
     *  @param output Output stream address
     *  @param critter Const address to Critter
     *  @return Address to output stream
     */
    friend std::ostream& operator<<(std::ostream& output, const Critter& critter) {
      output << "\tType: " << critter.critter_type << std::endl;
      output << "\tHit points: " << critter.hit_points << std::endl;
      output << "\tSteal strength: " << critter.steal_strength << " coins" << std::endl;
      output << "\tPlayer reward: " << critter.player_reward << " coins" << std::endl;
      output << "\tSpeed: " << critter.speed << std::endl;
      output << "\tLevel: " << critter.level << std::endl;
      return output;
    }

  protected:
    /** @brief Pure virtualized initialization function for Critter.
    *   @return Void.
    */
    virtual void initializeCritter() = 0;

    /** @brief Type of the Critter.
      */
    std::string critter_type;

    /** @brief Health of the Critter.
      */
    int hit_points;

    /** @brief Rate at which the critter can steal coins from the player.
      */
    int steal_strength;

    /** @brief Coin reward for the player when the Critter is killed 
      */
    int player_reward;

    /** @brief Critter movement speed 
      */
    float speed;

    /** @brief Difficulty level as part of a wave
      */
    int level;
};