#include "ability.h"

Ability::Ability(int _id, string _name, string _desc) {
  id = _id;
  name = _name;
  desc = _desc;
}
void Ability::LightningRod(Type attack, Individual &user) {
  if (attack == ELECTRIC) {

  }
}
