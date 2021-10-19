#ifndef GROUP_H
#define GROUP_H

#include "lootdefines.h"
#include "lootinterface.h"

class Item;


class Group
{
public:
    ~Group();
    LootError setData(const char* data, size_t& offset);
    void genLoot(std::mt19937& mtRand,
                 std::list<LootOut>& lootOutList,
                 const LootEngineInterface::LootEngineStruct& lootEngineStruct) const;
    static size_t getOffset();

    LootEngineInterface::GroupStruct  groupStruct;
    uint32_t childrenCount;
    Item* children = nullptr;
};

#endif // GROUP_H
