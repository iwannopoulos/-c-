#ifndef HEAP_H
#define HEAP_H
class heap{
    protected:
        int *tree;
        int capacity;
        int size;
        int parent(int key);
        int right(int key);
        int left(int key);
        virtual void heapifyUp(int i)=0;
        virtual void heapifyDown(int i)=0;
        //αυξανει το μεγεθος κατα 20
        void resize();
    public:
        //κενός κατασκεβαστής
        heap();
        //destractor
        ~heap();
        //επιστρέφει το μεγίστο/ελάχιστο στοιχείο αναλόγως την δομή 
        virtual int getMaxMin();
        //διαγράφει το μεγίστο/ελάχιστο στοιχείο αναλόγως την δομή 
        int deleteMaxMin();
        //επιστρέφει το μεγεθος της δομης
        int getSize();
        //εμφανίζει την τιμή του στοιχείου που βρίσκεται στην θεση Key
        int printItem(int key);
        //τοποθετεί το στοιχείο key στην δομή 
        void insert(int item);
};
#endif