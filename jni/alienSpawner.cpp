#include <lw.h>
#include <alienSpawner.h>

AlienSpawner::AlienSpawner(int id, std::string const& name, int maxStack) : Item(id) {
	this->setIcon("alien_spawner", 0);
	this->setDescriptionId(name);
	this->setMaxStackSize(maxStack);
	this->handEquipped();
	this->setCategory(3);
}

bool AlienSpawner::useOn(ItemInstance *itemStack, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3) {
	itemStack->count--;
	//spawn the alien here
}

