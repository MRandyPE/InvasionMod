#include <lw.h>
#include <alienSpawner.h>

AlienSpawner::AlienSpawner(int id, TextureUVCoordinateSet tex, std::string const& name, int maxStack, int damage) : Item(id) {
	this->setIcon(tex);
	this->setDescriptionId(name);
	this->setMaxStackSize(maxStack);
	this->attackDamage=damage;
	this->handEquipped();
	this->category=3;
}

int AlienSpawner::getAttackDamage(Entity* entity) {
	return this->attackDamage;
}

bool AlienSpawner::useOn(ItemInstance *itemStack, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3) {
	itemStack->count--;
	//spawn the alien here
}