#ifndef LOOT_H
#define LOOT_H

#include "lootdefines.h"
#include "lootinterface.h"

class Group;


class Loot
{
public:
    ~Loot();
    LootError setData(const char* data, size_t& offset);
    void genLoot(std::mt19937& mtRand,
                 std::list<LootOut>& lootOutList,
                 const LootEngineInterface::LootEngineStruct& lootEngineStruct) const;

    static size_t getOffset();

    LootEngineInterface::LootStruct  lootStruct;
    uint32_t childrenCount;
    Group* children = nullptr;
};

#endif // LOOT_H
