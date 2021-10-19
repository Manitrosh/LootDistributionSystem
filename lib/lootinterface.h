#ifndef LOOTINTERFACE_H
#define LOOTINTERFACE_H

#include <stdint.h>
#include <functional>
#include <list>

namespace LootEngineInterface {

enum StructType
{
    item,
    Group,
    Loot,
    Engine
};

struct ItemStruct
{
    uint32_t id;
    uint32_t count;
    uint32_t spread;
    uint32_t weight;
};

struct GroupStruct
{
    uint32_t sumWeight;
    uint16_t count;
    uint16_t spread;
    uint32_t key;
    uint32_t settings; //repeat + reserve
};

struct LootStruct
{
    uint32_t settings; //reserve
};

struct LootEngineStruct
{
//    using CallBackFunc = int(*)(int, StructType);
//    CallBackFunc callBackFunc = nullptr;

    std::function<void (int, StructType)> callBack = nullptr;
    uint32_t key;
    std::list<std::pair<uint32_t, uint32_t>> list;
};

}

#endif // LOOTINTERFACE_H
