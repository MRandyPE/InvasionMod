#pragma once
#include <lw.h>

class LightLayer;
class FullTile;
class TileTickingQueue;

class TileSource {
public:
	const Player* player;
	const bool allowUnpopulatedChunks;
	const bool publicSource;
	Level* level;
	ChunkSource* source;
	//ListenerSet listeners;
	LevelChunk* lastChunk;
	TileTickingQueue* tickQueue;
	//EntityList _tempEntityList;
	std::vector<AABB> _tempCubeList;
public:
	TileSource(Level &, ChunkSource *, bool, bool);
	TileSource(Player &);
	virtual ~TileSource();
	Level *getLevel() const;
	inline TileID getTile(int, int, int);
	inline TileID getTile(const TilePos &);
	inline int getData(int, int, int);
	inline int getData(const TilePos &);
	inline FullTile getTileAndData(int, int, int);
	inline FullTile getTileAndData(const TilePos &);
	Tile *getTilePtr(int, int, int);
	TileEntity *getTileEntity(int, int, int);
	TileEntity *getTileEntity(const TilePos &);
	bool setTile(int, int, int, TileID, int);
	bool setTileAndData(int, int, int, FullTile, int);
	int getBrightness(const LightLayer &, const TilePos &);
	int getBrightness(const LightLayer &, int, int, int);
	int getBrightness(const TilePos &);
	int getBrightness(int, int, int);
	bool canSeeSky(int, int, int);
	bool canSeeSky(const TilePos &);
	bool isSolidBlockingTile(int, int, int);
	bool isSolidBlockingTile(const TilePos &);
};