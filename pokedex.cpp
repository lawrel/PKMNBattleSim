#include "pokedex.h"
Pokedex::Pokedex() {

}
Pokedex::~Pokedex() {

}
int Pokedex::addEntry(Pokemon &pkmn){
  return 1;
}
Pokemon* Pokedex::getEntry(string name) {
  Pokemon * p = (*pkDex)[0];
  return p;
}
Pokemon* Pokedex::getEntry(int id) {
  Pokemon * p = (*pkDex)[id];
  return p;
}
void Pokedex::outputEntry(Pokemon &pkmn) {

}
