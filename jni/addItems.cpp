#define PI 3.14159265358979323846
#include <lw.h>
#include <weapons.h>
#include <tgmath.h>

ExampleItem::ExampleItem(int id, std::string const& icon, int addTex, std::string const& name, int maxStack, int damage) : Item(id) {
	this->setIcon(icon, addTex);
	this->setDescriptionId(name);
	this->setMaxStackSize(maxStack);
	this->attackDamage=damage;
	this->handEquipped();
	this->category=3;
}

int ExampleItem::getAttackDamage(Entity* entity) {
	return this->attackDamage;
}
