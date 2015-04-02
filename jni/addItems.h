#ifndef WEAPONS_H_
#define WEAPONS_H_

#define EXAMPLE_ITEM_ID 500

#include <lw.h>

class ExampleItem : public Item {
public:
    int attackDamage;
public:
    ExmapleItem(int, std::string const&, int, std::string const&, int, int);
    virtual int getAttackDamage(Entity*);
};

#endif