#include "List.h"
#include <iostream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "rus");
    MineralCollection<std::string> collection;
    collection.Add("�����", 7);
    collection.Add("�������", 3);
    collection.Add("������� ����", 6);
    collection.Add("������", 5);
    collection.Add("�������", 4);
    collection.Add("�����", 8);
    collection.Add("������", 9);
    collection.Add("�����", 10);
    collection.Add("�����", 49);
    collection.Print();

    MineralCollection<std::string>::Iterator it = collection.begin();
    do {
        std::cout << *it << " ";
        ++it;
    } while (it != collection.end());
    std::cout << std::endl;
    return 0;
}