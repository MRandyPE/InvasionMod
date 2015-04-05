#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>
#include <map>
#include <memory>
#include <lw.h>
#include <alienSpawner.h>
#include <GlowstoneTorch.h>
bool reg=false;
bool itemsAdded=false;

static void (*Minecraft_selectLevel_real)(Level*, Minecraft*, std::string const&, std::string const&, LevelSettings const&);
static void(*Gui_render_real)(Gui*, float, bool, int, int);
static void(*Tile_initTiles_real)();
static void(*CreativeInventoryScreen_populateItem_real)(Item*, int, int);
std::map <std::string, std::string>* I18n_strings;

static void addShapedRecipe(int id, int count, int damage, std::string line1, std::string line2, std::string line3, int ingCount, char charArray[], int idArray[]) {
	std::vector<std::string> shape={ line1, line2, line3};
	std::vector<Recipes::Type> ingredients;
	for(int n=0; n<ingCount; n++) {
		Recipes::Type recipeType;
		if(idArray[n]<=256) {
		    recipeType.tile=Tile::tiles[idArray[n]];
		    recipeType.item=NULL;
		}
		else {
			recipeType.tile=NULL;
			recipeType.item=Item::items[idArray[n]];
		}
		recipeType.c=charArray[n];
		ingredients.push_back(recipeType);
	}
	Recipes::getInstance()->addShapedRecipe(ItemInstance(id, count, damage), shape, ingredients);
}

static void Minecraft_selectLevel_hook(Level* level, Minecraft* mc, std::string const& str1, std::string const& str2, LevelSettings const& settings) {
	AlienSpawner* alienSpawner=new AlienSpawner(ALIEN_SPAWNER_ID-0x100, "Alien Spawner", 64);
	Item::items[ALIEN_SPAWNER_ID]=alienSpawner;
	if(!reg) {
		reg=true;
	    (*I18n_strings)["item.Alien Spawner.name"]="Spawn Alien Villager";
		(*I18n_strings)["tile.Glowstone Torch.name"]="Glowstone Torch";
		char gtChars[]={'g', 's'};
	    int gtIngs[]={348, 280};
	    addShapedRecipe(GLOWSTONE_TORCH_ID, 4, 0, "  ", " g ", " s ", 2, gtChars, gtIngs);
	}
	Minecraft_selectLevel_real(level, mc, str1, str2, settings);
}

static void Tile_initTiles_hook() {
	Tile_initTiles_real();
	GlowstoneTorch* glowstoneTorch = new GlowstoneTorch(GLOWSTONE_TORCH_ID, "Glowstone Torch");
	TileItem* glowstoneTorchItem=new TileItem(GLOWSTONE_TORCH_ID-0x100);
}

static void Gui_render_hook(Gui* gui, float f1, bool b1, int i1, int i2) {
	Gui_render_real(gui, f1, b1, i1, i2);
}

static void CreativeInventoryScreen_populateItem_hook(Item* item, int count, int damage) {
	if(!itemsAdded) {
		CreativeInventoryScreen_populateItem_real(Item::items[GLOWSTONE_TORCH_ID], 1, 0);
		CreativeInventoryScreen_populateItem_real(Item::items[ALIEN_SPAWNER_ID], 1, 0);
		itemsAdded=true;
	}
	CreativeInventoryScreen_populateItem_real(item, count, damage);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* CreativeInventoryScreen_populateItem=dlsym(RTLD_DEFAULT, "_ZN23CreativeInventoryScreen12populateItemEP4Itemii");
	I18n_strings = (std::map <std::string, std::string>*) dlsym(RTLD_DEFAULT, "_ZN4I18n8_stringsE");
	MSHookFunction((void*) &Gui::render, (void*) &Gui_render_hook, (void**) &Gui_render_real);
    MSHookFunction((void*) &Minecraft::selectLevel, (void*) &Minecraft_selectLevel_hook, (void**) &Minecraft_selectLevel_real);
    MSHookFunction((void*) &Tile::initTiles, (void*) &Tile_initTiles_hook, (void**) &Tile_initTiles_real);
	MSHookFunction(CreativeInventoryScreen_populateItem, (void*) &CreativeInventoryScreen_populateItem_hook, (void**) &CreativeInventoryScreen_populateItem_real);
    return JNI_VERSION_1_2;
}