#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "persona.h"
using namespace std;

int main()
{

    Queue<int>*cola=new Queue<int>();

    cola->insertar(10);
    cola->insertar(20);
    cola->insertar(30);
    cola->insertar(40);
    cola->insertar(100);
    cola->insertar(65);
    cola->insertar(5);
    cola->insertar(4);
    cola->insertar(110);
    cola->insertar(68);
    cola->insertar(2);
    cola->insertar(3);
    cola->insertar(25);
    cola->showList();


    //cout<<cola->dequeue()->getValue()<<endl;


    cola->vaciar();
    delete cola;
    return 0;
}
