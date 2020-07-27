#include "pkmn.h"
#include <stdlib.h>   
Pokemon::Pokemon(std::map<std::string, std::vector<std::string> >& facts) {
	map<string, vector<string> >::const_iterator itr = facts.begin();
	//read in the map and grab variables if they exist
	for (; itr != facts.end(); itr++) {
		switch (itr->first) {
		case "id":
			idNum = atoi(itr->second[0]);
			break;
		case "label":
			name = itr->second[0];
			break;
		case "species":
			species = itr->second[0];
			break;
		case "genderThreshold":
			genderDistribution = atoi(itr->second[0]);
			break;
		case "catchRate":
			catchRate = atoi(itr->second[0]);
			break;
		case "hatchCounter":
			hatchCount = atoi(itr->second[0]);
			break;
		case "height":
			height = atof(itr->second[0]);
			break;
		case "weight":
			weight = atof(itr->second[0]);
			break;
		case "baseExpYield":
			expYield = atoi(itr->second[0]);
			break;
		case "baseFriendship":
			baseFriendship = atoi(itr->second[0]);
			break;
		case "expGroup":
			growthPattern = atoi(itr->second[0]);
			break;
		case "color":
			color = itr->second[0];
			break;
		case "types":
			types = itr->second;
			break;
		case "abilities":
			for (int i = 0; (itr->second).size(); i++) {
				abilities.push_back(atoi((itr->second)[i]));
			}
			break;
		case "eggGroups":
			break;
		case "evYield":
			for (int i = 0; (itr->second).size(); i++) {
				evYield.push_back(atoi((itr->second)[i]));
			}
			break;
		case "baseStats":
			break;
		case "bodyStyle":
			bodyStyle = itr->second[0];
			break;
		}
	}
}
bool Pokemon::BreedCheck(Pokemon mate) {

}