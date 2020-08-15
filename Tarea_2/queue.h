#ifndef QUEUE_H
#define QUEUE_H
#include "nodogenerico.h"
#include "nodogenerico.cpp"
#include <iostream>
using namespace std;
template<class T>
class Queue
{
public:
    Queue();
    ~Queue();
    void enqueue(T valor);
    NodoGenerico<T>* dequeue();
    void vaciar();
private:
    NodoGenerico<T> *top;
    NodoGenerico<T> *bottom;
};

#endif // QUEUE_H
