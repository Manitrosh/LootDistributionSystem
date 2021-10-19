#include "group.h"
#include "item.h"

#include <random>

Group::~Group()
{
    if (children)
        delete[] children;
}

LootError Group::setData(const char* data, size_t& offset)
{
    LootError error = LootError::None;
    if (children)
        delete[] children;

    groupStruct = (*reinterpret_cast<const LootEngineInterface::GroupStruct*>(data + offset));
    offset += getOffset();

    if (childrenCount)
    {
        children = new Item[childrenCount];
        for (size_t groupIt = 0; groupIt < childrenCount; groupIt++)
        {
            error = static_cast<LootError>(error | children[groupIt].setData(data, offset));
        }
    }
    else
    {
        children = nullptr;
        error = static_cast<LootError>(error | LootError::None);
    }

    return error;
}

void Group::genLoot(std::mt19937& mtRand, std::list<LootOut>& lootOutList, const LootEngineInterface::LootEngineStruct& lootEngineStruct) const
{
    //all
    for (size_t groupIt = 0; groupIt < childrenCount; groupIt++)
    {
        if (mtRand() % groupStruct.sumWeight < children[groupIt].itemStruct.weight)
            lootOutList.push_back(children->getLootOut(mtRand));
    }


    //only one or zero
    unsigned long weight = mtRand() % groupStruct.sumWeight;
    for (size_t groupIt = 0; groupIt < childrenCount; groupIt++)
    {
        if (weight < children[groupIt].itemStruct.weight)
        {
            lootOutList.push_back(children->getLootOut(mtRand));
            break;
        }

        weight -= children[groupIt].itemStruct.weight;
    }
}

size_t Group::getOffset()
{
    return sizeof(Group) - sizeof(Item*);
}
