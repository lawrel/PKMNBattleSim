#ifndef __pkmn_h_
#define __pkmn_h_
#include "structures.h"
#include "items.h"

class Type {
    public:
    string TypeName;
    vector<string> weakTo;
    vector<string> resistantTo;
    vector<string> ineffective;
    bool isWeakTo(string type);
    bool isResistant(string type);
    bool isIneffective(string type);
};
class Move {
    public:
    void doAttack(Individual &attacker, Individual &defender);

    private:
    Type type;
    string desc;
    string move_type; //phys, spec, or none
    int power;
    int accuracy;
    Status statusEffect;
};
class Pokemon {
    public:
    bool BreedCheck(Pokemon mate);
    Pokemon EvolvesFrom;
    Pokemon EvolvesTo;
    map<int,Move> moveset;
    vector<Move> compatibleTMs;
    vector<Move> eggMoves;
    int growthPattern;
    int expYield;
    int catchRate;
    int hatchCount;
    int baseFriendship;
    int idNum;
    int genderDistribution;
    string DexEntry;
    string species;
    string color;
    string bodyStyle;
    Type type1;
    Type type2;
    bool isMonoType;

    vector<int> baseStats;
};
class Individual : public Pokemon {
    public:
    Individual(vector<string> info);;
    Individual();
    Individual(Individual &old);

    int getCurrHealth() { return currHealth;}

    void ExpGain(Individual enemy);
    void levelUp();
    void attacked(int damage);
    void heal();

    private:
    int currHealth;
    int maxHealth;
    int earnedExp;
    int level;
    Status status;
    string gender;
    vector<Move> moves;
    vector<int> currBuffs;
    vector<int> currStats;
    vector<int> evs;
    vector<int> ivs;
};