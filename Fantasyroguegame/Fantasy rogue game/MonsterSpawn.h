#include "Monster.h"
#include "MonsterFodder.h"
#include "MonsterBrute.h"
#include "MonsterRaider.h"

class MonsterFactory {
public:
	Monster* orderMonster(std::string type);
	Monster* createMonster(std::string type);
};
