#ifndef ALIENSPAWNER_H_
#define ALIENSPAWNER_H_

#define ALIEN_SPAWNER_ID 500

#include <lw.h>

class AlienSpawner : public Item {
public:
    int attackDamage;
public:
    AlienSpawner(int, TextureUVCoordinateSet, std::string const&, int, int);
    virtual int getAttackDamage(Entity*);
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
};

#endif