#include "pkmn.h"
#include "pokedex.h"
#include "structures.h"

class Side {
  public:
    Side();
  private:
    vector<Pokemon> party;
}
class Battle {
  public:
    Battle();
    void initFight();
  private:
    string battle_type;
    Side player;
    Side opponent;
};
