#include <iostream>
#include <string>
#include <CritterFactory.h>
#include <CritterWave.h>
#include <Map.h>
#include <Player.h>

int main(int argc, char** argv[]) {
  /**********************************************
     Creating critters using the CritterFactory
   **********************************************/
  std::cout << "Let's create some critters!" << std::endl;

  // Create a new Cat
  Critter* mr_meow = CritterFactory::createCritter(CritterFactory::CritterType::CAT);
  std::cout << "Critter 1:" << std::endl << *mr_meow;
  
  // Create a new Dog
  Critter* fido = CritterFactory::createCritter(CritterFactory::CritterType::DOG);
  std::cout << "Critter 2:" << std::endl << *fido;
  
  // Create a new Werecat
  Critter* scratches = CritterFactory::createCritter(CritterFactory::CritterType::WERECAT);
  std::cout << "Critter 3:" << std::endl << *scratches;
  
  // Create a new Werewolf
  Critter* jacob = CritterFactory::createCritter(CritterFactory::CritterType::WEREWOLF);
  std::cout << "Critter 4:" << std::endl << *jacob;

  /**************************
     Creating a map
  **************************/
  std::cout << "\nLet's create a map!" << std::endl;

  Map map = Map();

  std::cout << map << std::endl;
  std::cout << "X = Scenery cell" << std::endl
            << "P = Path cell" << std::endl
            << "S = Start cell" << std::endl
            << "E = Exit cell" << std::endl;

  /**************************
     Creating critter waves
   **************************/
  std::cout << "\nLet's create a critter wave!" << std::endl;

  // Create a wave of 9 cats
  CritterWave wave_of_meows(9, CritterFactory::CritterType::CAT);

  for (int i = 1; i <= wave_of_meows.numOfCritters; ++i) {
    wave_of_meows.addCritter(i, CritterFactory::createCritter(wave_of_meows.type));
  }
  
  std::cout <<  "Critters in this wave:\n" << wave_of_meows << std::endl;

  /**************************
    Following a path
  **************************/
  std::cout << "\nLet's follow the path of Critters 1 & 2!" << std::endl
            << "Critters will only move on path cells." << std::endl
            << "Watch Critter 2 follow the lead of Critter 1!\n" << std::endl;
  
  /* Create a player */ 
  Player player;

  /* Start */
  //Spawn first critter in wave at start
  wave_of_meows.spawnAtStartCell(1, 3, 1);

  Critter* critter1 = wave_of_meows.findCritter(1);
  Critter* critter2 = wave_of_meows.findCritter(2);

  std::cout << "Start: " << std::endl 
    << "Critter 1 is on cell " << critter1->getPosition() << std::endl
    << "Critter 2 is not spawned on the map yet." << std::endl;
  
  /* Update 1 */
  //Spawn second critter in wave at start
  wave_of_meows.spawnAtStartCell(2, 3, 1);

  critter1->chooseNextPathCell(map, critter1->row, critter1->col, player);

  std::cout << "Update 1: " << std::endl 
    << "Critter 1 is on cell " << critter1->getPosition() << std::endl
    << "Critter 2 is on cell " << critter2->getPosition() << std::endl;

  /* Update 2 */
  critter1->chooseNextPathCell(map, critter1->row, critter1->col, player);
  critter2->chooseNextPathCell(map, critter2->row, critter2->col, player);

  std::cout << "Update 2: " << std::endl 
    << "Critter 1 is on cell " << critter1->getPosition() << std::endl
    << "Critter 2 is on cell " << critter2->getPosition() << std::endl;

  /* Update 3 */
  critter1->chooseNextPathCell(map, critter1->row, critter1->col, player);
  critter2->chooseNextPathCell(map, critter2->row, critter2->col, player);

  std::cout << "Update 3: " << std::endl 
    << "Critter 1 is on cell " << critter1->getPosition() << std::endl
    << "Critter 2 is on cell " << critter2->getPosition() << std::endl;

  /******************************************************
    Reaching the exit and stealing coins from the player
  *******************************************************/
  std::cout << "\nLooks like Critter 1 has reached the exit!" << std::endl
            << "Player, prepare to lose some coins!" << std::endl;
  
  std::cout << player << std::endl;

  /* Update 4 */
  critter1->chooseNextPathCell(map, critter1->row, critter1->col, player);
  critter2->chooseNextPathCell(map, critter2->row, critter2->col, player);

  std::cout << "Update 4: " << std::endl 
    << "Critter 1 is on cell " << critter1->getPosition() << std::endl
    << "Critter 2 is on cell " << critter2->getPosition() << std::endl;

  std::cout << "Critter 1 says: \"MUHAHAHA, I've stolen " << critter1->getStealStrength() << " coins!" << std::endl;
  std::cout << player << std::endl;
  
  /* Update 5 */
  critter1->chooseNextPathCell(map, critter1->row, critter1->col, player);
  critter2->chooseNextPathCell(map, critter2->row, critter2->col, player);

  std::cout << "Update 4: " << std::endl 
    << "Critter 2 is on cell " << critter2->getPosition() << std::endl;

  std::cout << "Critter 2 says: \"MUHAHAHA, now I've stolen " << critter1->getStealStrength() << " coins!" << std::endl;
  std::cout << player << std::endl;
  
  /******************************************************
    Critter takes damage from towers
  *******************************************************/
  std::cout << "\nLet's get back at those thieving critters!" << std::endl
            << "When Critters move into the range of a tower, they lose health." << std::endl
            << "Critters die if they have no more hit points!" << std::endl;

  std::cout << "\nLet's create a second map with a tower on it!" << std::endl;

  Map map2 = Map();
  map2.placeTower(2, 4);

  std::cout << map2 << std::endl;
  std::cout << "X = Scenery cell" << std::endl
            << "P = Path cell" << std::endl
            << "S = Start cell" << std::endl
            << "E = Exit cell" << std::endl
            << "T = Cell with tower" << std::endl;

  std::cout << "\nOur towers have a strike range of one cell all around them." << std::endl
            << "So, critters walking on the path cells (3,3) and (3,4) will take damage." << std::endl;

  std::cout << "\nLet's create a wave of only one critter to test this!" << std::endl;
 
  // Create a wave of 1 cat (forever alone)
  CritterWave a_lone_meow(1, CritterFactory::CritterType::CAT);
  
  a_lone_meow.addCritter(1, CritterFactory::createCritter(a_lone_meow.type));

  /* Start */  
  //Spawn first critter in wave at start
  a_lone_meow.spawnAtStartCell(1, 3, 1);

  Critter* critter = a_lone_meow.findCritter(1);

  std::cout << "Start: " << std::endl 
    << "Critter is on cell " << critter->getPosition() << std::endl
    << "Critter says: \"I'm safe! Totally not in range. Meow.\"" << std::endl
    << "Critter health: " << critter->getHitPoints() << std::endl;

    /* Update 1 */

  critter->chooseNextPathCell(map, critter->row, critter->col, player);

  std::cout << "Update 1: " << std::endl 
    << "Critter is on cell " << critter->getPosition() << std::endl
    << "Critter says: \"I'm safe! Totally not in range. Meow.\"" << std::endl
    << "Critter health: " << critter->getHitPoints() << std::endl,

  /* Update 2 */

  critter->chooseNextPathCell(map, critter->row, critter->col, player);
  critter->takeDamage(map2.map[1][3].strengthOfAttack);

  std::cout << "Update 2: " << std::endl 
    << "Critter is on cell " << critter->getPosition() << std::endl
    << "Critter says: \"I'm hit! That hurts. HISSST.\"" << std::endl
    << "Critter health: " << critter->getHitPoints() << std::endl;

  /* Update 3 */

  critter->chooseNextPathCell(map, critter->row, critter->col, player);
  critter->takeDamage(map2.map[1][3].strengthOfAttack);

  std::cout << "Update 3: " << std::endl 
    << "Critter is on cell " << critter->getPosition() << std::endl
    << "Critter says: \"I'm hit! That hurts. HISSST.\"" << std::endl
    << "Critter health: " << critter->getHitPoints() << std::endl;

  if (critter->getHitPoints() <= 0) {
    std::cout << "RIP, Critter!" << std::endl;
    // Remove dead Critter from the wave
    a_lone_meow.removeCritter(1);
  }



  return 0;
}