/** @file CritterFactory.h
 *  @brief File for CritterFactory class.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <Critter.h>
#include <Cat.h>
#include <Dog.h>
#include <Werecat.h>
#include <Werewolf.h>

/** @brief Creates objects derived from Critter.
 *  Utility class that creates instance of a Critter subclass
 *  from a family of derived Critter classes. 
 */
class CritterFactory {
  public:
    enum CritterType { CAT, DOG, WERECAT, WEREWOLF };

    /** @brief Factory method for Critter class.
    *   @return Critter object (subclass of Critter).
    */
    static Critter *createCritter(CritterType type);
};