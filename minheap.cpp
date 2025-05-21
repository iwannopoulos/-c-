#ifndef MINHEAP_CPP
#define MINHEAP_CPP
#include "minheap.h"
minheap::minheap():heap(){}
minheap::~minheap(){}

void minheap::heapifyUp(int i){
    if(i==1){return;}   //  Σωστη θεση
    if(i>size){return;} //Εκτος οριων
    if(tree[i]<tree[parent(i)]){
        int temp=tree[i];
        tree[i]=tree[parent(i)];
        tree[parent(i)]=temp;
        return heapifyUp(parent(i));
    }
    return;
}
void minheap::heapifyDown(int i){
    if(i>size){return;} //εκτος οριων
    int key=i;
    if(left(i)<=size && tree[i]>tree[left(i)]){
        key=left(i);
    }
    if(right(i)<=size && tree[key]>tree[right(i)])
    {
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