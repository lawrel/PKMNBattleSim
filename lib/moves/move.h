
#include <vector>
#include <string>
#include <map>
#include <structures.h> 

using namespace std;

class Move {
    public:
      Move(map<string, vector<string>>& facts);
    private:
    Type type;
    string desc;
    string move_type; //phys, spec, environment or none
    string target;
    int power;
    int accuracy;
    Status statusEffect;
    int statusChance;
    Weather weatherEffect;
    int weatherChance;
    vector<int> statmods;
    int modchance;
    float recoil;
    int pp;
    int priority;
    int contact;

};