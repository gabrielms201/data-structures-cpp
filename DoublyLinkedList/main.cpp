#include <iostream>
#include "List.h"

int main(int argc, char* argv[])
{
    List list = List();
    list.insert(1);
    list.insert(2);
    list.insert(3);

    bool found1 = list.find(1);
    bool found2 = list.find(2);
    bool found3 = list.find(3);
    bool found4 = list.find(312312);

    bool remove1 = list.remove(1);
    auto remove2 = list.remove(2);
    bool remove3 = list.remove(3);


    list.insert(4);
    list.insert(5);
    list.insert(6);
    //bool remove4 = list.remove(4);

    list.clear();
    list.insert(7);
    list.insert(8);
    list.insert(9);

    std::cout << "Hello World";
}