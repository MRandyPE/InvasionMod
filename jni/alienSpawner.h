#ifndef WEAPONS_H_
#define WEAPONS_H_

#define ALIEN_SPAWNER_ID 500

#include <lw.h>

class AlienSpawner : public Item {
public:
    int attackDamage;
public:
    AlienSpawner(int, std::string const&, int, std::string const&, int, int);
    virtual int getAttackDamage(Entity*);
};

#endif