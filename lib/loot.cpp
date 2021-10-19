#include "loot.h"
#include "group.h"


Loot::~Loot()
{
    if (children)
        delete[] children;
}

LootError Loot::setData(const char *data, size_t &offset)
{
    LootError error = LootError::None;
    if (children)
        delete[] children;

    lootStruct = *reinterpret_cast<const LootEngineInterface::LootStruct*>(data + offset);
    offset += getOffset();

    if (childrenCount)
    {
        children = new Group[childrenCount];
        for (size_t lootIt = 0; lootIt < childrenCount; lootIt++)
        {
            error = static_cast<LootError>(error | children[lootIt].setData(data, offset));
        }
    }
    else
    {
        children = nullptr;
        error = static_cast<LootError>(error | LootError::None);
    }

    return error;
}

void Loot::genLoot(std::mt19937& mtRand, std::list<LootOut>& lootOutList, const LootEngineInterface::LootEngineStruct& lootEngineStruct) const
{
    for (size_t lootIt = 0; lootIt < childrenCount; lootIt++)
        children[lootIt].genLoot(mtRand, lootOutList, lootEngineStruct);
}

size_t Loot::getOffset()
{
    return sizeof(Loot) - sizeof(Group*);
}
