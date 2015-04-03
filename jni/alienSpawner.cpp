#include <lw.h>
#include <alienSpawner.h>

AlienSpawner::AlienSpawner(int id, std::string const& name, int maxStack) : Item(id) {
	TextureUVCoordinateSet referenceTextures = Item::getTextureUVCoordinateSet("compass_item", 0);
	referenceTextures.startX = 0.8125F;
	referenceTextures.endX = 0.875F;
	this->setIcon(referenceTextures);
	this->setDescriptionId(name);
	this->setMaxStackSize(maxStack);
	this->handEquipped();
	this->category=3;
}

bool AlienSpawner::useOn(ItemInstance *itemStack, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3) {
	itemStack->count--;
	//spawn the alien here
}

