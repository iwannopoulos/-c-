//
// Created by xrhstos on 5/21/2025.
//
#include <stdio.h>
#include <fstream>
#include <cstring>
#include "heap.h"
#include "maxheap.h"
#include "minheap.h"
#include "AVLTree.h"
using namespace std;
int main() {
    string value;//Για το διάβασμα των commands


    ifstream input("commands.txt");
    ofstream output("output.txt",ios::app);

    //Αρχικοποίηση μεταβλητών
    int num,i;

    //Αρχικοποίηση Δομών Δεδομένων
    minheap minheap;
    maxheap maxheap;
    AVLTree avltree;


    while (!input.eof())
    {
        input >> value ; //το value  παίρνει τις τιμές (BUILD ,GETSIZE ,FINDMIN ,FINDMAX ,INSERT ,DELETEMIN, DELETEMAX, SEARCH, DELETE)
        if (value == "BUILD") {
            input  >> value; //το value  παίρνει τις τιμές (MINHEAP MAXHEAP HASHTABLE AVLTREE GRAPH)
            ifstream input1; //inputstream για διάβασμα απο το αρχείο , του οποίου το όνομα περιέχεται στο commands.txt μετά από το MINHEAP,MAXHEAP...)
            if (value == "MINHEAP")
            {
                input >> value; //όνομα του αρχείου
                input1.open(value);
                while (input1 >> num)//όσο υπάρχουν αριθμοί στο αρχείο θα είναι true
                {
                    minheap.insert(num);
                }
                input1.close();//κλείσιμο του αρχείου απο το οποίο έγινε η ανάγνωση των αριθμών
                output << "MINHEAP: ";// γράφει στο output.txt MINHEAP:
                for (i=1;i<=minheap.getSize();++i)
                {
                    output << minheap.printItem(i) << " ";
                } //και στη συνέχεια γράφει στο output.txt τους αριθμούς που διαβάστηκαν προηγουμένος
                output << "\n"; //κενό για καλύτερη εικόνα
            } else if (value == "MAXHEAP")
            {
                input >> value; //όνομα αρχείου
                //η ιδία διαδικασία απλά για το maxheap
                input1.open(value);
                while (input1 >> num)
                {
                    maxheap.insert(num);
                }
                input1.close();
                output << "MAXHEAP: ";
                for(i=1;i<=maxheap.getSize();i++)
                {
                    output << maxheap.printItem(i) << " ";
                }
                output <<"\n";
            }else if (value=="AVLTREE")
            {
                input>>value;//ονόμα αρχείου
                input1.open(value);
                while(input1 >> num)
                {
                    avltree.insert(num);
                }
                input1.close();

            }
        }
    }
}