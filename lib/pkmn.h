#ifndef __pkmn_h_
#define __pkmn_h_
#include "structures.h"


class Pokemon {
    public:
        Pokemon(const map<string,vector<string> >& facts);
        Pokemon();
        //Pokemon(Pokemon& old);
        Type getType1() {return type1;};
        Type getType2() {return type2;};
        void printPkmnData();
        int getBaseStat(Stat s);

    int EvolvesFrom;
    int EvolvesTo;
    map<int,Move> moveset;
    vector<Move> compatibleTMs;
    vector<Move> eggMoves;
    int growthPattern;
    int expYield;
    int catchRate;
    int hatchCount;
    int baseFriendship;
    int idNum;
    float height;
    float weight;
    int genderDistribution;
    string DexEntry;
    string species;
    string name;
    string color;
    string bodyStyle;
    Type type1;
    Type type2;
    string EggGroup1;
    string EggGroup2;
    bool isMonoType;
private:
    vector<int> baseStats;
    vector<int> abilities;
    vector<int> evYield;
};
class Individual : public Pokemon {
    public:
    Individual(vector<string> info);
  //  Individual(Pokemon spec, int min, int max);
    Individual();
    //Individual(Individual &old);

    string getName() {return nname;}
    void calculateStats();
    void nickname(string newName) {nname = newName;}
    int getCurrHealth() { return currHealth;}
    bool BreedCheck(Individual mate);
    void ExpGain(Individual enemy);
    void levelUp();
    void Evolve();
    void attacked(int damage);
    void heal(int healnum);
    int performAttack(Move move);
    float getEggChance(Individual mate, bool OvalCharm);

    private:
    string nname;
    int OT;
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
    Nature nature;
};
#endif
