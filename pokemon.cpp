#include "pkmn.h"
#include <math.h>
Pokemon::Pokemon(const map<string,vector<string> >& facts) {
	map<string,vector<string> >::const_iterator itr = facts.begin();
	//read in the map and grab variables if they exist
	for(;itr!=facts.end();itr++) {
		if(itr->first=="id") {
			idNum = stoi(itr->second[0]);
		} else if (itr->first=="label") {
			name = itr->second[0];
		} else if (itr->first=="species") {
			species = itr->second[0];
		} else if (itr->first=="genderThreshold") {
			genderDistribution= stoi(itr->second[0]);
		} else if (itr->first=="catchRate") {
			catchRate = stoi(itr->second[0]);
		} else if (itr->first=="hatchCounter") {
			hatchCount = stoi(itr->second[0]);
		} else if (itr->first=="height") {
			height = stof(itr->second[0]);
		} else if (itr->first=="weight") {
			weight = stof(itr->second[0]);
		} else if (itr->first=="baseExpYield") {
			expYield = stoi(itr->second[0]);
		} else if (itr->first=="baseFriendship") {
			baseFriendship = stoi(itr->second[0]);
		} else if (itr->first=="expGroup") {
			growthPattern = stoi(itr->second[0]);
		} else if (itr->first=="color") {
			color = itr->second[0];
		} else if (itr->first=="types") {
			type1 = getTypeFromString(itr->second[0]);
			if ((itr->second).size()==2) {
				type2 = getTypeFromString(itr->second[1]);
			} else {type2 = getTypeFromString(itr->second[0]);}
		} else if (itr->first=="abilities") {
			for (size_t i = 0; i < itr->second.size(); i++) {
				abilities.push_back(stoi(itr->second[i]));
			}
		} else if (itr->first=="eggGroups") {
			EggGroup1 = itr->second[0];
			if ((itr->second).size()==2) {
				EggGroup2 = itr->second[1];
			} else {EggGroup2 = itr->second[0];}
		} else if (itr->first=="evYield") {
			for (size_t i = 0; i < itr->second.size(); i++) {
				evYield.push_back(stoi(itr->second[i]));
			}
		} else if (itr->first=="baseStats") {
			for (size_t i = 0; i < itr->second.size(); i++) {
				baseStats.push_back(stoi(itr->second[i]));
			}
		} else if (itr->first=="bodyStyle") {
			bodyStyle = itr->second[0];
		}
	}
}
Pokemon::Pokemon() {

}
int Pokemon::getBaseStat(Stat s) {
	return baseStats[s];
}
void Pokemon::printPkmnData() {
	printf("#%d: %s the %s Pokemon\n", idNum, name.c_str(), species.c_str());
}
//USAGE: Create random individual of pokemon species
/*Individual::Individual(Pokemon spec, int min, int max) {
}*/
int stat_helper(int value,Stat curr, Stat p, Stat m) {
	if (curr==p) {
		return floor(value*1.1);
	} else if (curr==m) {
		return floor(value*0.9);
	}
	return value;
}
void Individual::calculateStats() {
	int partial;
	currStats[HP] = floor(((2*getBaseStat(HP)+ivs[HP]+(evs[HP]/4))*level)/100)+level+10;
	partial = floor(((2*getBaseStat(ATTACK)+ivs[ATTACK]+(evs[ATTACK]/4))*level)/100)+5;
	currStats[ATTACK] = stat_helper(partial,ATTACK,nature.plus,nature.minus);
	currStats[DEFENSE] = stat_helper(partial,DEFENSE,nature.plus,nature.minus);
	currStats[SPATK] = stat_helper(partial,SPATK,nature.plus,nature.minus);
	currStats[SPDEF] = stat_helper(partial,SPDEF,nature.plus,nature.minus);
	currStats[SPEED] = stat_helper(partial,SPEED,nature.plus,nature.minus);
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
