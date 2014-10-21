/** @file Map.h
 *  @brief Representation of Map object.
 *
 *  This is the representation of the Map object.
 *
 *  @author Stephanie Li
 */

#pragma once
#include <iostream>
#include <string>

/** @brief Class for Map.
 *  Stub class of map for Critters. 
 */
class Map {
  public:
    enum CellType { SCENERY, PATH, START, EXIT, TOWER };
    static const int map_size = 5;
    
    Map() {
      // Quick and dirty initialization of Cells in the map
      for (int i = 0; i < map_size; ++i) {
        for (int j = 0; j < map_size; ++j) {
          if (i == 2) {
            if (j == 0) {
              map[i][j] = StartCell();
            } else if (j == 4) {
              map[i][j] = ExitCell();
            } else {
              map[i][j] = PathCell();
            }
          } else {
            map[i][j] = SceneryCell();
          }
        }
      }
    }
    ~Map() {};

    /** @brief Set a scenery cell to a tower cell.
     *  @param row Row position of new tower.
     *  @param col Col position of new tower.
     *  @return Void.
     */    
    void placeTower(int row, int col) {
      if (map[row-1][col-1].type == SCENERY) {
        map[row-1][col-1].hasTower = true;
        map[row-1][col-1] = TowerCell();
      }
    }

    /** @brief Overloaded cout operator to print out Maps.
     *  @param output Output stream address
     *  @param critter Const address to Map
     *  @return Address to output stream
     */
    friend std::ostream& operator<<(std::ostream& output, const Map& map) {
      output << "  12345" << std::endl;
      for (int i = 0; i < 5; ++i) {
        output << i + 1 << " ";
        for (int j = 0; j < 5; ++j) {
          if (map.map[i][j].type == START) {
            output << 'S';
          } 
          if (map.map[i][j].type == EXIT) {
            output << 'E';
          }
          if (map.map[i][j].type == PATH) {
            output << 'P';
          } 
          if (map.map[i][j].type == SCENERY) {
            output << 'X';
          }
          if (map.map[i][j].type == TOWER) {
            output << 'T';
          }      
        } output << std::endl;  
      }
      return output;
    }
    
   /** @brief Base struct for Cell objects in a Map.
    */
    struct Cell {
      CellType type;
      bool hasTower;
      int strengthOfAttack;
      Cell() {
        hasTower = false;
      }
    };
   
    /** @brief Derived from base struct Cell.
    */
    struct SceneryCell : Cell {
      bool hasTower;
      SceneryCell() {
        type = SCENERY;
      }
    };

   /** @brief Derived from base struct Cell.
    */
    struct PathCell : Cell {
      PathCell() {
        type = PATH;
      }
    };

   /** @brief Derived from base struct Cell.
    */
    struct StartCell : Cell {
      StartCell() {
        type = START;
      }
    };

    /** @brief Derived from base struct Cell.
    */
    struct ExitCell : Cell {
      ExitCell() {
        type = EXIT;
      }
    };

   /** @brief Derived from base struct Cell.
    */
    struct TowerCell : Cell {
      TowerCell() {
        type = TOWER;
        strengthOfAttack = 5;
      }
    };

   /** @brief 2D array representing the map grid.
    */
    Map::Cell map [map_size][map_size];
};