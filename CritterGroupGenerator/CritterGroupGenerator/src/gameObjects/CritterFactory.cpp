#include <CritterFactory.h>

/**  The only method in CritterFactory, createCritter() cranks out 
  *  Critter objects based on the enum parameter. 
  */
Critter* CritterFactory::createCritter(CritterType type) {
  switch (type) {
    case CAT:
      return new Cat;
    case DOG:
      return new Dog;
    case WERECAT:
      return new Werecat;
    case WEREWOLF:
      return new Werewolf;
    default:
      return NULL;
  }
}