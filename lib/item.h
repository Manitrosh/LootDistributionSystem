#ifndef ITEM_H
#define ITEM_H

#include "lootdefines.h"
#include "lootinterface.h"


class Item
{
public:
    LootError setData(const char* data, size_t& offset);
    LootOut getLootOut(std::mt19937& mtRand) const;
    static size_t getOffset();

    LootEngineInterface::ItemStruct itemStruct;
};

#endif // ITEM_H
