#include <GlowstoneTorch.h>
#include "mcpe/tile/TorchTile.h"

GlowstoneTorch::GlowstoneTorch(int id, std::string const& desc) : TorchTile(id, desc) {
	TextureUVCoordinateSet referenceTexture = Tile::getTextureUVCoordinateSet("wool", 13);
	referenceTexture.endX = 0.1875;
	referenceTexture.startY = 0.6875;
	referenceTexture.endY = 0.8125;
	this->tex = referenceTexture;
	this->setLightEmission(0.85F);
	this->setCategory(2);
}