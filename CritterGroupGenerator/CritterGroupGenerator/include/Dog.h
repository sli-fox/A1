/** @file Dog.h
 *  @brief Representation of Dog object.
 *
 *  This is the representation of the Dog object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <Critter.h>

/** @brief Class for Dog.
 *  Subclass of Critter. 
 */
class Dog : public Critter {
  public:

    Dog();
    ~Dog() {};
    
  private:
    /** @brief Initialization function for a Dog.
     *  @return Void.
     */
    virtual void initializeCritter();
};