#include <GlowstoneTorch.h>
#include "mcpe/level/TileSource.h"

GlowstoneTorch::GlowstoneTorch(int id, std::string const& desc) : Tile(id, &Material::decoration) {
	TextureUVCoordinateSet referenceTexture = Tile::getTextureUVCoordinateSet("wool", 13);
	referenceTexture.endX = 0.1875;
	referenceTexture.startY = 0.6875;
	referenceTexture.endY = 0.8125;
	this->tex = referenceTexture;
	this->setDescriptionId(desc);
	this->setTicking(true);
	this->setLightEmission(0.85F);
	this->setCategory(2);
	Tile::tiles[id] = this;
	Tile::solid[id] = false;
}

bool GlowstoneTorch::mayPlace(TileSource* ts, int x, int y, int z) {
	return Tile::torch->mayPlace(ts, x, y, z);
}

void GlowstoneTorch::animateTick(TileSource* ts, int x, int y, int z, Random* rand) {
	Tile::torch->animateTick(ts, x, y, z, rand);
}

/*bool GlowstoneTorch::checkCanSurvive(TileSource* ts, int x, int y, int z) {
	if(!this->mayPlace(ts, x, y, z)) {
		if(ts->getTilePtr(x, y, z) == this) {
			this->spawnResources(ts, x, y, z, ts->getData(x, y, z), 0.0F);
			ts->setTile(x, y, z, Tile::tiles[0]->id, 3);
		}
	}
}*/

AABB* GlowstoneTorch::getAABB(TileSource* ts, int x, int y, int z, AABB& aabb, int i1, bool b1, int i2) {
	return Tile::torch->getAABB(ts, x, y, z, aabb, i1, b1, i2);
}

int GlowstoneTorch::getIconYOffset() const {
	return Tile::torch->getIconYOffset();
}

void GlowstoneTorch::getPlacementDataValue(Mob* mob, int x, int y, int z, signed char sc1, float f1, float f2, float f3, int i1) {
	return Tile::torch->getPlacementDataValue(mob, x, y, z, sc1, f1, f2, f3, i1);
}

void GlowstoneTorch::getShape(TileSource* ts, int x, int y, int z, AABB& aabb, bool b1) {
	return Tile::torch->getShape(ts, x, y, z, aabb, b1);
}

bool GlowstoneTorch::isConnection(TileSource& ts, int x, int y, int z) {
	if(ts.isSolidBlockingTile(x, y, z)) {
		return true;
	} else {
		Tile* tileRef = ts.getTilePtr(x, y, z);
		return tileRef == Tile::fence || tileRef == Tile::glass || tileRef == Tile::cobbleWall;
	}
}

void GlowstoneTorch::neighborChanged(TileSource* ts, int i1, int i2, int i3, int i4, int i5, int i6) {
	return Tile::torch->neighborChanged(ts, i1, i2, i3, i4, i5, i6);
}

void GlowstoneTorch::onPlace(TileSource* ts, int x, int y, int z) {
	return Tile::torch->onPlace(ts, x, y, z);
}

void GlowstoneTorch::tick(TileSource* ts, int x, int y, int z, Random* rand) {
	return Tile::torch->tick(ts, x, y, z, rand);
}