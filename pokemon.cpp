#include "pkmn.h"

Pokemon::Pokemon(const map<string, vector<string> >& facts) {
	map<string, vector<string> >::const_iterator itr = facts.begin();
	//read in the map and grab variables if they exist
	for (; itr != facts.end(); itr++) {
		if (itr->first=="id") {
			idNum = stoi(itr->second[0]);
		} else if (itr->first=="label") {
			name = itr->second[0];
		} else if (itr->first=="species") {
			species = itr->second[0];
		} else if (itr->first=="genderThreshold") {
			genderDistribution = stoi(itr->second[0]);
		} else if (itr->first=="catchRate") {
			catchRate = stoi(itr->second[0]);
		} else if (itr->first=="hatchCounter") {
			hatchCount = stoi(itr->second[0]);
		} else if(itr->first=="height") {
			height = stoi(itr->second[0]);
		} else if (itr->first=="weight") {
			weight = stoi(itr->second[0]);
		} else if (itr->first=="baseExpYield") {
			expYield = stoi(itr->second[0]);
		} else if(itr->first=="baseFriendship") {
			baseFriendship = stoi(itr->second[0]);
		} else if (itr->first=="expGroup") {
			expGroup = stoi(itr->second[0]);
		} else if (itr->first=="color") {
			color = itr->second[0];
		} else if (itr->first=="bodyStyle") {
			bodyStyle = itr->second[0];
		} else if (itr->first=="baseStats") {
			for (int i = 0; (itr->second).size(); i++) {
				baseStats.push_back(stoi(itr->second[i]));
			}
		} else if (itr->first=="eggGroups") {
			if (itr->second.size()==1) {
				EggGroup1 = itr->second[0];
				EggGroup2 = itr->second[0];
			} else if (itr->second.size()==2) {
				EggGroup1 = itr->second[0];
				EggGroup2 = itr->second[1];
			} else {
				perror("ERROR: Incorrect egg group information provided");
			}
		} else if (itr->first=="types") {
			if (itr->second.size()==1) {
				type1 = itr->second[0];
				type2 = itr->second[0];
				isMonoType = true;
			} else if (itr->second.size()==2) {
				type1 = itr->second[0];
				type2 = itr->second[1];
				isMonoType = false;
			} else {
				perror("ERROR: incorrect type information provided");
			}
		} else if (itr->first=="evYield") {
			for (int i = 0; (itr->second).size(); i++) {
				evYield.push_back(stoi(itr->second[i]));
			}
		} else if (itr->first=="abilities") {
			for (int i = 0; (itr->second).size(); i++) {
				abilities.push_back(stoi(itr->second[i]));
			}
		}

	}
}
//USAGE: Create random individual of pokemon species
Individual::Individual(Pokemon spec, int min, int max) {

}
void Individual::heal(int healnum) {
	currHealth+=healnum;
	if(currHealth > maxHealth) {
		currHealth = maxHealth;
	}
}
bool Individual::BreedCheck(Individual mate) {
	if (EggGroup1=="Undiscovered"||EggGroup2=="Undiscovered"||
	mate.EggGroup1=="Undiscovered"||mate.EggGroup2=="Undiscovered") {
		return false;
	}
	else if (EggGroup1=="Ditto"||mate.EggGroup1=="Ditto") {
		if(EggGroup1==mate.EggGroup1) {return false;}
		return true;
	}
	if (gender=="none"||mate.gender == "none") {
		if(name == mate.name) {
			return true;
		}
		return false;
	}
	if (gender==mate.gender) {return false;}
	if (EggGroup1 == mate.EggGroup1 || EggGroup2 == mate.EggGroup1 ||
	EggGroup1 == mate.EggGroup2 || EggGroup2 == mate.EggGroup2) {
		return true;
	}
	return false;
}
float Individual::getEggChance(Individual mate, bool OvalCharm) {
	if (BreedCheck(mate)) {
		if(name == mate.name) {
			if(OT!=mate.OT && OvalCharm) {return 0.88;}
			if (OT!=mate.OT) {return 0.7;}
			return 0.5;
		}
		else if (OT != mate.OT && OvalCharm) { return 0.7;}
		else if(OvalCharm) {return 0.4;}
		return 0.2;
	}
	return 0.0;
}
