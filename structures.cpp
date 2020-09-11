#include "structures.h"

float calculateMatchup(Type attack, Type type1, Type type2) {
  if (attack == NONE) {
    return 1;
  }
  if (type1==type2) {
    return rawData[attack][type1];
  }
  return rawData[attack][type1]*rawData[attack][type2];
}
Type getTypeFromString(string const& input) {
  if (input=="Normal") return NORMAL;
  if(input=="Fighting") return FIGHTING;
  if (input=="Flying") return FLYING;
  if(input=="Poison") return POISON;
  if (input=="Ground") return GROUND;
  if(input=="Rock") return ROCK;
  if (input=="Bug") return BUG;
  if(input=="Ghost") return GHOST;
  if (input=="Steel") return STEEL;
  if(input=="Fire") return FIRE;
  if (input=="Water") return WATER;
  if(input=="Grass") return GRASS;
  if (input=="Electric") return ELECTRIC;
  if(input=="Psychic") return PSYCHIC;
  if (input=="Ice") return ICE;
  if(input=="Dragon") return DRAGON;
  if (input=="Dark") return DARK;
  if(input=="Fairy") return FAIRY;
  return NONE;
}
string outputType(Type type) {return typeNames[type];}
