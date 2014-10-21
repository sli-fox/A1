/** @file Werecat.h
 *  @brief Representation of Werecat object.
 *
 *  This is the representation of the Werecat object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <Critter.h>

/** @brief Class for Werecat.
 *  Subclass of Critter. 
 */
class Werecat : public Critter {
  public:

    Werecat();
    ~Werecat() {};
    
  private:
    /** @brief Initialization function for a Werecat.
     *  @return Void.
     */
    virtual void initializeCritter();
};