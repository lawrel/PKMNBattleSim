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
class pkmnType {
  public:
    pkmnType();
    pkmnType(map<string, vector<string>>);
    string name;
    vector<string> weakTo;
    vector<string> resistantTo;
    vector<string> ineffective;
    bool isWeakTo(string type);
    bool isResistant(string type);
    bool isIneffective(string type);
};

class Move {
    public:
      Move();
    private:
    string type;
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
  map<string, pkmnType> typeDex;
  map<string, Move> moveDex;
};
#endif
