#include "MonsterSpawn.h"
#include <string>

Monster* MonsterFactory::orderMonster(std::string type) {
	Monster* newMonster;//creates a new monster
	newMonster = createMonster(type);//creates monster with parameter type chosen at spawn
	return newMonster;//returns the monster
}

//the type now passes on to the correct monster
Monster* MonsterFactory::createMonster(std::string type) {
	if ( type == "fodder" ) return new MonsterFodder();
    if ( type == "brute" ) return new MonsterBrute();
	if ( type == "raider" ) return new MonsterRaider();
    return NULL;
}