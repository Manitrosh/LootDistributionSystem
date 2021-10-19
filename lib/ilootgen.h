#ifndef ILOOTGEN_H
#define ILOOTGEN_H

#include "lootdefines.h"
#include "lootinterface.h"


class ILootGen
{
public:
    virtual LootError setData(const char* data, size_t& offset) = 0;
    virtual void genLoot(std::mt19937& mtRand,
                         std::list<LootOut>& lootOutList,
                         const LootEngineInterface::LootEngineStruct& lootEngineStruct) const = 0;
};

#endif // ILOOTGEN_H
