/** @file Cat.h
 *  @brief Representation of Cat object.
 *
 *  This is the representation of the Cat object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <Critter.h>

/** @brief Class for Cat.
 *  Subclass of Critter. 
 */
class Cat : public Critter {
  public:

    Cat();
    ~Cat() {};
    
  private:
    /** @brief Initialization function for a Cat.
     *  @return Void.
     */
    virtual void initializeCritter();
};