//
// Created by xrhstos on 5/21/2025.
//
#include "hashtable.h"

//it returns the possition where the key will be stored
int hashtable::hashfunction(int key)
{
    return key %10;
}

//increases the size of i array by 5
void hashtable::resize(int i)
{
    int j;
    int *newhash=new int[capacity[i]+5];
    for(j=0;j<capacity[i];j++)
    {
        newhash[j]=hash[i][j];
    }
    delete [] hash[i];
    hash[i]=newhash;
    capacity[i]+=5;

}

//constructor
hashtable::hashtable()
{
    int i;
    hash=new int*[10];
    for(i=0;i<10;++i)
    {
        hash[i]=new int [10];
        size[i]=0;
        capacity[i]=10;
    }
}

//methods

//inserts Item in hashtable
void hashtable::InsertItem(int key)
{
    int j,i=hashfunction(key);
    if(size[i]==capacity[i])
    {
        resize(i);
    }
    for(j=0;j<size[i];j++)
    {
        if(hash[i][j]==key)
        {
            return; //key already exists
        }
    }
    hash[i][size[i]]=key;
    size[i]++;
}

//Searches hashtable for key if it Finds it,it returns SUCCESS else it returns FAILURE
string hashtable::SearchItem(int key)
{
    int j,i=hashfunction(key);
    for(j=0;j<size[i];j++)
    {
        if(hash[i][j]==key)
        {
            return "SUCCESS";
        }
    }
    return "FAILURE";

}

//It returns the current size of hashtable
int hashtable::getSize()
{
    int i,sum=0;
    for(i=0;i<10;i++)
    {
        sum+=size[i];
    }
    return sum;
}