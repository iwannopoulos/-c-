#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "heap.h"
class maxheap:public heap{
    private:
        void heapifyUp(int i)   override;
        void heapifyDown(int i) override;
    public:
        //κατασκεβαστής maxheap
        maxheap();
        //destructor maxheap
        ~maxheap();
};
#endif