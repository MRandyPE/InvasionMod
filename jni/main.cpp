#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>
#include <map>


static Item* createItem(int id, std::string name, std::string icon, int addTextures, int maxStackSize) {
    Item* newItem=(Item*) ::operator new((std::size_t)76);
    Item_item(newItem, id-0x100);
    Item_setIcon(newItem, icon, addTextures);
    Item_setDescriptionId(newItem, name);
    //ya no se ve como item.itemname.name
 (*I18n_strings)["item."+name+".name"]=name;
    Item_setMaxStackSize(newItem, maxStackSize);
    Item::items[id]=newItem;
    return newItem; 
}
 
static void Minecraft_selectLevel_hook(Level* level, Minecraft* mc, std::string const& str1, std::string const& str2, LevelSettings const& settings) {
    //Item
    Tunder=createItem(504, "Potato Poisonous", "potato_poisonous", 0, 1);
    
    //nuevo item de equipacion
    Item_handEquipped(fallSword);
    mobHarvest=createItem(504, "Potato Poisonous", "potato_poisonous", 0, 1);
    Item_handEquipped(mobHarvest);
    //hace el default de Minecraft::selectLevel
    Minecraft_selectLevel_real(level, mc, str1, str2, settings);
}
 
static int Player_getCarriedItemId(Player* player) {
    if(Player_getCarriedItem(player)==NULL)
        return 0;
    else if(Player_getCarriedItem(player)!=NULL)
        return ItemInstance_getId(Player_getCarriedItem(player));
}






JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

Item_item=(void(*)(Item*, int)) dlsym(RTLD_DEFAULT, "_ZN4ItemC2Ei");

const char* error = dlerror();
if(error) __android_log_print(ANDROID_LOG_INFO, TAG, "dlerror: %s", error);
return JNI_VERSION_1_2;
}