#ifndef LOOTENGINE_H
#define LOOTENGINE_H

#include "loot.h"

class LootEngine
{
public:
    LootEngine();
    void setRandomKey(uint64_t randomKey);
    uint64_t getRandomKey() const;
    LootError loadData(const char* data, size_t size);
    std::list<LootOut> genLoot();

private:
    uint64_t _randomKey;
    Loot _loot;
    LootEngineInterface::LootEngineStruct _lootEngineStruct;
};

#endif // LOOTENGINE_H
