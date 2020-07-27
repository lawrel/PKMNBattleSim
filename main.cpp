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
#include "pokemon.h"

bool ReadPkmnInfo(std::istream& istr, std::map<std::string, std::vector<std::string> >& facts) {
    std::string token1, token2;
    char c;
    bool valid = false;
    facts.clear();
    while (istr >> token) {

        // Each character is delimited by curly braces.
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
                // We expect square brackets to delimit each vector
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

int main() {
    return 0;
}