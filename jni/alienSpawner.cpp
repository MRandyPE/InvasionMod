#include <lw.h>
#include <alienSpawner.h>

AlienSpawner::AlienSpawner(int id, std::string const& icon, int addTex, std::string const& name, int maxStack, int damage) : Item(id) {
	this->setIcon(icon, addTex);
	this->setDescriptionId(name);
	this->setMaxStackSize(maxStack);
	this->attackDamage=damage;
	this->handEquipped();
	this->category=3;
}

int AlienSpawner::getAttackDamage(Entity* entity) {
	return this->attackDamage;
}
