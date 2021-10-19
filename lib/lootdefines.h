#ifndef LOOTDEFINES_H
#define LOOTDEFINES_H

#include <stdint.h>
#include <stddef.h>
#include <list>
#include <random>

struct LootOut
{
    uint32_t id;
    uint32_t count;
};

enum LootError : uint32_t
{
    None        = 0x0,
    DataLenght  = 0x1,
    Version     = 0x2,
    EmptyGroup  = 0x4,
    EmptyLoot   = 0x8
};

template <typename T>
struct ChildrenStruct
{
    uint32_t childrenCount;
    T* children = nullptr;
};




#endif // LOOTDEFINES_H
