/** @file Werewolf.h
 *  @brief Representation of Werewolf object.
 *
 *  This is the representation of the Werewolf object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <Critter.h>

/** @brief Class for Werewolf.
 *  Subclass of Critter. 
 */
class Werewolf : public Critter {
  public:

    Werewolf();
    ~Werewolf() {};
    
  private:
    /** @brief Initialization function for a Werewolf.
     *  @return Void.
     */
    virtual void initializeCritter();
};