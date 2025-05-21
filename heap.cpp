#ifndef HEAP_CPP
#define HEAP_CPP
#include "heap.h"
heap::heap(){
    tree=new int[20];
    capacity=19;
    size=0;
}
heap::~heap(){
    delete[] tree;
}
int heap::getSize(){
    return size;
}
int heap::printItem(int key){
    return tree[key];
}
void heap::insert(int item){
    if(size==capacity){
        resize();
    }
    tree[++size]=item;
    heapifyUp(size);
}
void heap::resize(){
    int i;                                                                                        
    int *newheap=new int[capacity+20];   
    for(i=0;i<=size;i++){
        newheap[i]=tree[i];   
    }
    delete [] tree;
    tree=newheap;
    capacity+=20;
}
int heap::parent(int key){
    return key/2;
}
int heap::left(int key){
    return key*2;
}
int heap::right(int key){
    return key*2+1;
}
int heap::getMaxMin(){
    return tree[1];
}
int heap::deleteMaxMin()
{
    int max=tree[1];
    tree[1]=tree[size--];
    heapifyDown(1);
    return max;
}

#endif