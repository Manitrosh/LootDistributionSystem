#include "item.h"


LootError Item::setData(const char* data, size_t& offset)
{
    LootError error = LootError::None;
    itemStruct = *reinterpret_cast<const LootEngineInterface::ItemStruct*>(data + offset);
    offset += getOffset();

    return error;
}

LootOut Item::getLootOut(std::mt19937& mtRand) const
{
    if (itemStruct.spread == 0)
        return {itemStruct.id, itemStruct.count};

    return {itemStruct.id, static_cast<uint32_t>(itemStruct.count + mtRand() % itemStruct.spread)};
}

size_t Item::getOffset()
{
    return sizeof(Item);
}
