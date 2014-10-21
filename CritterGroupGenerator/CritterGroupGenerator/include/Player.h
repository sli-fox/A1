/** @file Player.h
 *  @brief Representation of Player object.
 *
 *  This is the representation of the Player object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <iostream>
#include <string>

/** @brief Class for Player.
 *  Stub class of Player for Critters. 
 */
class Player {
  public:
    Player() {
      numOfCoins = 50;
    }
    
    int getCoins() const {
      return numOfCoins;
    }

    void addCoins(int coins) {
      numOfCoins += coins;
    }

    void removeCoins(int coins) {
      numOfCoins -= coins;
    }

    /** @brief Overloaded cout operator to print out Playerss.
     *  @param output Output stream address
     *  @param critter Const address to Player
     *  @return Address to output stream
     */
    friend std::ostream& operator<<(std::ostream& output, const Player& player) {
      output << "Player's coins: " << player.numOfCoins << std::endl;
      return output;
    }
  private:
    int numOfCoins;
};