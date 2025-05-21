//
// Created by xrhstos on 5/21/2025.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstring>
#include <iostream>
using namespace std;
class hashtable
{
private:
    int **hash;
    int size[10],capacity[10];

    //it returns the possition where the key will be stored
    int hashfunction(int key);

    //increases the size of i array by 5
    void resize(int i);
public:

    //constructor
    hashtable();
    //methods

    //inserts Item in hashtable
    void InsertItem(int key);

    //Searches hashtable for key if it Finds it,it returns SUCCESS else it returns FAILURE
    string SearchItem(int key);

    //It returns the current size of hashtable
    int getSize();
};

#endif
