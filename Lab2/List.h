#ifndef LIST_H
#define LIST_H

#include "MineralStone.h"
#include <iostream>

template <typename T>
class MineralCollection {
private:
    MineralStone<T>* head;

public:
    MineralCollection() : head(nullptr) {}
    ~MineralCollection() {
        if (head == nullptr) {
            return;
        }

        MineralStone<T>* curr = head;
        do {
            MineralStone<T>* next_stone = curr->next;
            delete curr;
            curr = next_stone;
        } while (curr != head);

        head = nullptr;
    }

    void Add(T name, int hardness) {
        MineralStone<T>* stone = new MineralStone<T>(name, hardness);

        if (head == nullptr) {
            head = stone;
        }
        else {
            MineralStone<T>* curr = head;
            while (curr->next != head && curr->next->hardness < hardness) {
                curr = curr->next;
            }
            if (curr == head && curr->hardness > hardness) {
                stone->next = curr;
                stone->prev = curr->prev;
                head = stone;
            }
            else {
                stone->next = curr->next;
                stone->prev = curr;
            }
            stone->next->prev = stone;
            stone->prev->next = stone;
        }
    }

    void Print() {
        MineralStone<T>* curr = head;
        do {
            std::cout << curr->name << " (" << curr->hardness << ") ";
            curr = curr->next;
        } while (curr != head);

        std::cout << std::endl;
    }

    class Iterator {
    private:
        MineralStone<T>* curr;
        MineralStone<T>* head;
        int prev_hardness;

    public:
        Iterator(MineralStone<T>* start, MineralStone<T>* head) : curr(start), head(head), prev_hardness(start->hardness) {}

        void operator++() {
            double x = pow(prev_hardness, 3);
            while (curr->next != head && curr->next->hardness != x) {
                curr = curr->next;
            }
            if (curr->next->hardness == x) {
                prev_hardness = curr->hardness;
                curr = curr->next;
            }
            else if (curr->next == head) {
                curr = curr->next;
            }
        }

        T operator*() {
            return curr->name;
        }

        bool operator!=(const Iterator& other) {
            return curr != other.curr;
        }
    };

    Iterator begin() {
        return Iterator(head, head);
    }

    Iterator end() {
        return Iterator(head, head);
    }
};

#endif 