#ifndef __pokedex_h_
#define __pokedex_h_
#include "pkmn.h"

class Pokedex {
  public:
    Pokedex();
    ~Pokedex();
    int addEntry(Pokemon &pkmn);
    Pokemon* getEntry(string name);
    Pokemon* getEntry(int id);
    void outputEntry(Pokemon &pkmn);
    void sortbyName();
    void sortbyColor();

  private:
    vector<Pokemon*>* pkDex;
};
#endif
