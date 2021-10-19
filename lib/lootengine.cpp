#include "lootengine.h"
#include "item.h"
#include "group.h"

#include <random>

#define CURRENT_VERSION 1


LootEngine::LootEngine()
{

}

void LootEngine::setRandomKey(uint64_t randomKey)
{
    _randomKey = randomKey;
}

uint64_t LootEngine::getRandomKey() const
{
    return _randomKey;
}

LootError LootEngine::loadData(const char* data, size_t size)
{
    if (size < sizeof(uint32_t) + sizeof(Loot) + sizeof(Group) + sizeof(Item))
        return LootError::DataLenght;

    if (*reinterpret_cast<const uint32_t*>(data) == CURRENT_VERSION)
        return LootError::Version;

    return _loot.setData(data, size);
}

std::list<LootOut> LootEngine::genLoot()
{
    std::mt19937 mtRand(_randomKey);
    std::list<LootOut> lootOutList;

    _loot.genLoot(mtRand, lootOutList, _lootEngineStruct);

    return lootOutList;
}

