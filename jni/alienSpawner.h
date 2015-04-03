#ifndef ALIENSPAWNER_H_
#define ALIENSPAWNER_H_

#define ALIEN_SPAWNER_ID 500

#include <lw.h>

class AlienSpawner : public Item {
public:
    AlienSpawner(int, std::string const&, int);
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
};

#endif