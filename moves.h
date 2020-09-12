#include "pkmn.h"
#include "structures.h"

//moves which have special effects that require unique handlers
void HiddenPower(Pokemon &target);
void Roar(Pokemon &target); //the chance of failing is FLOOR(T / 4) / (T + U + 1), where T is the target's level and U is the user's level
void MirrorMove(Pokemon &target);
void MagicCoat(Pokemon &target);
void Facade(Pokemon &target);
void Thief(Pokemon &target); // 99.6% chance to steal the target's held item (if it has one, and the user does not have one). cannot steal if hits a Pokémon's Substitute. Held Mail cannot be stolen. 
void EchoedVoice(Pokemon &target);
void FalseSwipe(Pokemon &target);
void DreamEater(Pokemon &target);
void Pluck(Pokemon &target);
void GrassKnot(Pokemon &target);
