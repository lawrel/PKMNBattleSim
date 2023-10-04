#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include "pkmn.h"

/*PKMN INFO ORDER: idNum, name, species, [types], [abilities], genderThreshold, catchRate,
[eggGroups], hatchCounter, height, weight, expYield, baseFriendship, expgroup, [evYield],
bodyStyle, color, [baseStats], dexEntry, EvolvesFrom, EvolvesTo, [compatibleTMs], [ lvl: moves ]
[eggMoves], FormeName
*/
bool ReadMoveInfo(istream& istr, map<string, vector<string> >& facts ) {
  string token,token2;
  bool valid = false;
  facts.clear();
  while(istr>>token) {
    if (token == "{") {
        assert(valid == false);
        valid = true;
      }
      else if (token == "}") {
        assert(valid == true);
        return true;
      }
      else {
        istr>>token2;
        assert(token2 == ":");
        if (token=="name") {
          istr >> token2;
          facts[token].push_back(token2);
          assert(facts[token].size() == 1);
        }
        else if (token=="statmods") {
          istr >> token2;
          assert(token2 == "[");
          while (istr >> token2) {
              if (token2 == "]") {
                  break;
              }
              facts[token].push_back(token2);
          }
          assert(facts[token].size() > 0);
        }
      }
    }
    return false;
}
bool ReadPkmnInfo(istream& istr, map<string, vector<string> >& facts) {
    string token, token2;
    char c;
    bool valid = false;
    facts.clear();
    while (istr >> token) {
        if (token == "{") {
            assert(valid == false);
            valid = true;
        }
        else if (token == "}") {
            assert(valid == true);
            return true;
        }
        else {
            istr >> token2;
            assert(token2 == ":");

            if (token == "id" || token == "label" || token == "species" ||
                token == "genderThreshold" || token == "catchRate" ||
                token == "hatchCounter" || token == "height" || token == "weight" ||
                token == "baseExpYield" || token == "baseFriendship" ||
                token == "expGroup" || token == "color") {
                istr >> token2;
                facts[token].push_back(token2);
                assert(facts[token].size() == 1);
            }
            else if (token == "types" || token == "abilities" || token == "eggGroups" ||
                token == "evYield" || token == "baseStats") {
                istr >> token2;
                assert(token2 == "[");
                while (istr >> token2) {
                    if (token2 == "]") {
                        break;
                    }
                    facts[token].push_back(token2);
                }
                assert(facts[token].size() > 0);
            }
            else if (token == "bodyStyle") {
                istr >> c;
                std::string t;
                assert(c == '"');
                while (istr >> std::noskipws >> c) {
                    if (c == '"') break;
                    t.push_back(c);
                }
                facts[token].push_back(t);
                istr >> std::skipws;
            }
            else {
                std::cerr << "ERROR!  unknown fact type " << token << std::endl;
                exit(1);
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
  string pokedexFile = "";
  string outputLog = "";
  if(argc!=3) {
    printf("ERROR: USAGE: ./a.out <pokedex file> <output file>\n");
    exit(EXIT_FAILURE);
  }
  pokedexFile = argv[1];
  outputLog = argv[2];
  if (pokedexFile=="") {
    cerr<<"ERROR: Did not provide pokedex file."<<endl;
    exit(EXIT_FAILURE);
  }
  if (outputLog=="") {
    cerr<<"ERROR: Did not provide output file."<<endl;
    exit(EXIT_FAILURE);
  }
  ifstream istr(pokedexFile.c_str());
  if (!istr.good()) {
    cerr<<"ERROR: Could not open pokedex file."<<endl;
    exit(EXIT_FAILURE);
  }
  ofstream ostr(outputLog.c_str());
  if (!ostr.good()) {
    cerr<<"ERROR: Could not open outputfile."<<endl;
    exit(EXIT_FAILURE);
  }
  std::vector<Pokemon> pokemons;
  while (1) {
    map<string,vector<string> > facts;
    if (!ReadPkmnInfo(istr,facts)) break;
    Pokemon p = Pokemon(facts);
    // add the new pokemon to the master container
    pokemons.push_back(p);
  }
  for (size_t i = 0; i < pokemons.size(); i++) {
    pokemons[i].printPkmnData();
    cout<<"Types: "<<outputType(pokemons[i].getType1())<<" "<<outputType(pokemons[i].getType2())<<endl;
  }
  cout<<"Fire type attack on Grass Type does x"<<calculateMatchup(FIRE, GRASS, GRASS)<<" damage"<<endl;
  cout<<outputType(FIRE)<<" type attack on Grass/Bug Type does x"<<calculateMatchup(FIRE, GRASS, BUG)<<" damage"<<endl;
  cout<<"Fire type attack on Water Type does x"<<calculateMatchup(FIRE, WATER, WATER)<<" damage"<<endl;
  cout<<"Water type attack on Water/Dragon Type does x"<<calculateMatchup(WATER, WATER, DRAGON)<<" damage"<<endl;
  cout<<"Normal type attack on Ghost/Water Type does x"<<calculateMatchup(NORMAL, GHOST, WATER)<<" damage"<<endl;
  cout<<"Normal type attack on Ghost Type does x"<<calculateMatchup(NORMAL, GHOST, GHOST)<<" damage"<<endl;
  cout<<outputType(NONE)<<" type attack on Grass/Bug Type does x"<<calculateMatchup(NONE, GRASS, BUG)<<" damage"<<endl;
  return 0;
}
