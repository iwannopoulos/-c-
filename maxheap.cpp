#ifndef MAXHEAP_CPP
#define MAXHEAP_CPP
#include "maxheap.h"
maxheap::maxheap():heap(){}
maxheap::~maxheap(){}



void maxheap::heapifyUp(int i){
    if(i==1){return;}   //Σωστη θεση
    if(i>size){return;} //εκτος οριων
    if(tree[i]>tree[parent(i)]){
        int temp=tree[i];
        tree[i]=tree[parent(i)];
        tree[parent(i)]=temp;
        return heapifyUp(parent(i));
    }
    return;
}
void maxheap::heapifyDown(int i){
    if(i>size){return;} //In this case the element is out of bounds
    int key=i;
    if(left(i)<=size && tree[i]<tree[left(i)]){
        key=left(i);
    }
    if(right(i)<=size && tree[key]<tree[right(i)]){
        key=right(i);
    }
    if(key!=i)
    {
        int temp=tree[i];
        tree[i]=tree[key];
        tree[key]=temp;
        heapifyDown(key);
    }
}
#endif