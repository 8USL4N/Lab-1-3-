#include "List.h"
#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "rus");
    MineralCollection<std::string> collection;
    collection.Add("Кварц", 7);
    collection.Add("Кальцит", 3);
    collection.Add("Полевой шпат", 6);
    collection.Add("Апатит", 5);
    collection.Add("Флюорит", 4);
    collection.Add("Топаз", 8);
    collection.Add("Корунд", 9);
    collection.Add("Алмаз", 27);
    collection.Add("Рубин", 125);
    collection.Print();

    MineralCollection<std::string>::Iterator it = collection.begin();
    do {
        std::cout << *it << " ";
        ++it;
    } while (it != collection.end());
    std::cout << std::endl;
    return 0;
}