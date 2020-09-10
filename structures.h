#ifndef __structures_h_
#define __structures_h_
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


enum Status {
    PARALYZE,
    POISONE,
    BAD_POISON,
    BURN,
    FROZE,
    SLEEP,
    BOUND,
    CONFUSION,
    TRAPPED,
    CURSED,
    EMBARGO,
    ENCORE,
    INFATUATED,
    HEAL_BLOCK,
    TAUNT,
    TORMENT,
    IDENTIFIED,
    CHARGING,
    RECHARGING,
    OK
};
enum Weather {
    CLEAR,
    RAIN,
    SUNNY,
    HAIL,
    SANDSTORM,
    STRONG_WIND,
    STRONG_RAIN,
    STRONG_SUN
};
enum Type {
  NORMAL = 0,
  FIGHTING,
  FLYING,
  POISON,
  GROUND,
  ROCK,
  BUG,
  GHOST,
  STEEL,
  FIRE,
  WATER,
  GRASS,
  ELECTRIC,
  PSYCHIC,
  ICE,
  DRAGON,
  DARK,
  FAIRY,
  NONE
};
float rawData[18][18] = {
  {1,  1,  1,  1,  1,0.5,  1,  0,0.5,  1,  1,  1,  1,  1,  1,  1,  1,  1}, //NORMAL
  {2,  1,0.5,0.5,  1,  2,0.5,  0,  2,  1,  1,  1,  1,0.5,  2,  1,  2,0.5}, //FIGHTING
  {1,  2,  1,  1,  1,0.5,  2,  1,0.5,  1,  1,  2,0.5,  1,  1,  1,  1,  1}, //FLYING
  {1,  1,  1,0.5,0.5,0.5,  1,0.5,  0,  1,  1,  2,  1,  1,  1,  1,  1,  2}, //POISON
  {1,  1,  0,  2,  1,  2,0.5,  1,  2,  2,  1,0.5,  2,  1,  1,  1,  1,  1},//GROUND
  {1,0.5,  2,  1,0.5,  1,  2,  1,0.5,  2,  1,  1,  1,  1,  2,  1,  1,  1}, //ROCK
  {1,0.5,0.5,0.5,  1,  1,  1,0.5,0.5,0.5,  1,  2,  1,  2,  1,  1,  2,0.5}, //BUG
  {0,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  1,  1,0.5,  1}, //GHOST
  {1,  1,  1,  1,  1,  2,  1,  1,0.5,0.5,0.5,  1,0.5,  1,  2,  1,  1,  2}, //STEEL
  {1,  1,  1,  1,  1,0.5,  2,  1,  2,0.5,0.5,  2,  1,  1,  2,0.5,  1,  1}, //FIRE
  {1,  1,  1,  1,  2,  2,  1,  1,  1,  2,0.5,0.5,  1,  1,  1,0.5,  1,  1}, //WATER
  {1,  1,0.5,0.5,  2,  2,0.5,  1,0.5,0.5,  2,0.5,  1,  1,  1,0.5,  1,  1}, //GRASS
  {1,  1,  2,  1,  0,  1,  1,  1,  1,  1,  2,0.5,0.5,  1,  1,0.5,  1,  1},//ELECTRIC
  {1,  2,  1,  2,  1,  1,  1,  1,0.5,  1,  1,  1,  1,0.5,  1,  1,  0,  1}, //PSYCHIC
  {1,  1,  2,  1,  2,  1,  1,  1,0.5,0.5,0.5,  2,  1,  1,0.5,  2,  1,  1},//ICE
  {1,  1,  1,  1,  1,  1,  1,  1,0.5,  1,  1,  1,  1,  1,  1,  2,  1,  0},//DRAGON
  {1,0.5,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  1,  1,0.5,0.5}, //DARK
  {1,  2,  1,0.5,  1,  1,  1,  1,0.5,0.5,  1,  1,  1,  1,  1,  2,  2,  1} //FAIRY
};

float calculateMatchup(Type attack, Type type1, Type type2);
Type getTypeFromString(string const& input);

class Move {
    public:
      Move();
    private:
    Type type;
    string desc;
    string move_type; //phys, spec, or none
    int power;
    int accuracy;
    Status statusEffect;
    int statusChance;
    Weather weatherEffect;
    int weatherChance;
};
class Constants {
  map<string, Move> moveDex;
};
#endif
