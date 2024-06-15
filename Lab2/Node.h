#pragma once

template<class T>
struct Node {
    Node* next;
    T data;
    Node(T info) : data(info), next(nullptr) {}
};