#ifndef MINERALSTONE_H
#define MINERALSTONE_H

template <typename T>
struct MineralStone {
    T name;
    int hardness;
    MineralStone* next;
    MineralStone* prev;

    MineralStone(T name, int hardness) : name(name), hardness(hardness), next(this), prev(this) {}
};

#endif 