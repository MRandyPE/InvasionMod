#ifndef GLOWSTONETORCH_H_
#define GLOWSTONETORCH_H_

#define GLOWSTONE_TORCH_ID 202
#include <lw.h>

class GlowstoneTorch : public Tile {
public:
	GlowstoneTorch(int, std::string const&);
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual bool checkCanSurvive(TileSource*, int, int, int);
	virtual AABB *getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
	virtual int getIconYOffset() const;
	virtual void getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int);
	virtual void getShape(TileSource*, int, int, int, AABB&, bool);
	virtual bool isConnection(TileSource&, int, int, int);
	virtual bool mayPlace(TileSource*, int, int, int);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void onPlace(TileSource*, int, int, int);
	virtual void tick(TileSource*, int, int, int, Random*);
};

#endif