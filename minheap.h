#ifndef MINHEAP_H
#define MINHEAP_H
#include "heap.h"
class minheap:public heap{
    private:
        void heapifyUp(int i)   override;
        void heapifyDown(int i) override;
    public:
        //κατασκεβαστής minheap
        minheap();
        //destructor minheap
        ~minheap();
        
        
};
#endif