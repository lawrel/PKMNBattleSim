#include "structures.h"

Nature::Nature(string _name, Natures _id, Stat _plus, Stat _minus, string l, string d) {
  name = _name;
  id = _id;
  plus = _plus;
  minus = _minus;
}
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
  //TODO: ORGANIZE BY MOST COMMON->LEAST COMMON TYPES
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

vector<Nature> initNatures() {
  vector<Nature> nats;
  nats.push_back(Nature("Adamant",ADAMANT,ATTACK,SPATK,"spicy","dry")); //0
  nats.push_back(Nature("Bashful",BASHFUL,NO_STAT,NO_STAT,"","")); //1
  nats.push_back(Nature("Bold",BOLD,DEFENSE,ATTACK,"sour","spicy"));
  nats.push_back(Nature("Brave",BRAVE,ATTACK,SPATK,"spicy","dry"));
  nats.push_back(Nature("Calm",CALM,SPDEF,ATTACK,"bitter","spicy"));
  nats.push_back(Nature("Careful",CAREFUL,SPDEF,SPATK,"bitter","dry")); //5
  nats.push_back(Nature("Docile",DOCILE,NO_STAT,NO_STAT,"",""));
  nats.push_back(Nature("Gentle",GENTLE,SPDEF,DEFENSE,"bitter","sour"));
  nats.push_back(Nature("Hardy",HARDY,NO_STAT,NO_STAT,"",""));
  nats.push_back(Nature("Hasty",HASTY,SPEED,DEFENSE,"sweet","sour"));
  nats.push_back(Nature("Impish",IMPISH,DEFENSE,SPATK,"sour","dry")); //10
  nats.push_back(Nature("Jolly",JOLLY,SPEED,SPATK,"sweet","dry"));
  nats.push_back(Nature("Lax",LAX,DEFENSE,SPDEF,"spicy","bitter"));
  nats.push_back(Nature("Lonely",LONELY,ATTACK,DEFENSE,"spicy","sour"));
  nats.push_back(Nature("Mild",MILD,SPATK,DEFENSE,"dry","sour"));
  nats.push_back(Nature("Modest",MODEST,SPATK,ATTACK,"dry","spicy")); //15
  nats.push_back(Nature("Naive",NAIVE,SPEED,SPDEF,"sweet","bitter"));
  nats.push_back(Nature("Naughty",NAUGHTY,ATTACK,SPDEF,"spicy","bitter"));
  nats.push_back(Nature("Quiet",QUIET,SPATK,SPEED,"dry","sweet"));
  nats.push_back(Nature("Quirky",QUIRKY,NO_STAT,NO_STAT,"",""));
  nats.push_back(Nature("Rash",RASH,SPATK,SPDEF,"dry","bitter")); //20
  nats.push_back(Nature("Relaxed",RELAXED,DEFENSE,SPEED,"spicy","sweet"));
  nats.push_back(Nature("Sassy",SASSY,SPDEF,SPEED,"bitter","sweet"));
  nats.push_back(Nature("Serious",SERIOUS,NO_STAT,NO_STAT,"",""));
  nats.push_back(Nature("Timid",TIMID,SPEED,SPATK,"sweet","dry")); //24
  return nats;
}
