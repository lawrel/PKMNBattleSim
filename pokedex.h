#ifndef __pokedex_h_
#define __pokedex_h_
#include "pkmn.h"

class Pokedex {
  public:
    Pokedex();
    ~Pokedex();
    int addEntry(int id, Pokemon &pkmn);
    Pokemon* getEntry(string name);
    Pokemon* getEntry(int id);
    void outputEntry(Pokemon &pkmn);
  private:
    map<int, Pokemon> *pkDex;
};
#endif
