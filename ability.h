#include "pkmn.h"

class Ability {
  public:
    Ability(int _id, string _name, string _desc);
    void LightningRod(Type attack, Individual &user);
    string name;
    string desc;
  private:
    Weather weather;
    int weatherChance;
    int id;
    Status prevents;
    Type powerup;
    Status contactEffect;
};
