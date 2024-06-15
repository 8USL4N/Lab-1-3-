#ifndef ITERATOR_H
#define ITERATOR_H

#include "List.h"

template <typename T>
class MineralCollection<T>::Iterator {
private:
    MineralStone<T>* curr;
    MineralStone<T>* head;
    int prev_hardness;

public:
    Iterator(MineralStone<T>* start, MineralStone<T>* head) : curr(start), head(head), prev_hardness(start->hardness) {}

    void operator++();
    T operator*();
    bool operator!=(const Iterator& other);
};

#endif 