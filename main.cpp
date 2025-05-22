//
// Created by xrhstos on 5/21/2025.
//

#include <fstream>
#include <cstring>
#include "heap.h"
#include "maxheap.h"
#include "minheap.h"
#include "AVLTree.h"
#include "hashtable.h"
using namespace std;
int main() {
    string value;//Για το διάβασμα των commands


    ifstream input("commands.txt");
    ofstream output("output.txt",ios::app);

    //Αρχικοποίηση μεταβλητών
    int num,i;
    string flag;

    //Αρχικοποίηση Δομών Δεδομένων
    minheap minheap;
    maxheap maxheap;
    AVLTree avltree;
    hashtable hashtable;




    while (!input.eof()) {
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
            }else if (value=="GRAPH"){

            }
        }else if (value=="GETSIZE"){
            input>>value;
            if (value=="MINHEAP") {
                output<<"MINHEAP SIZE:";
                output<<minheap.getSize();
                output<<"\n";
            }else if (value=="MAXHEAP") {
                output<<"MAXHEAP SIZE:";
                output<<maxheap.getSize();
                output<<"\n";
            }else if (value=="AVLTREE"){
                output<<"AVLTREE SIZE:";
                output<<avltree.size();
                output<<"\n";
            }else if (value=="GRAPH"){
                output<<"GRAPH SIZE:";
                output<<0;
            }else if (value=="HASHTABLE"){
                output<<"HASHTABLE SIZE:";
                output<< hashtable.getSize();
                output<<"\n";
            }
        }else if (value=="FINDMIN") {
            input>>value;
            if (value=="MINHEAP"){
                output<<"MINHEAP MIN:";
                output<<minheap.getMaxMin();
                output<<"\n";
            }else if (value=="MAXHEAP") {
                output<<"MAXHEAP MIN:";
                output<<maxheap.getMaxMin();
                output<<"\n";
            }else if (value=="AVLTREE") {
                output<<"AVLTREE MIN:";
                output<<avltree.minnode(avltree.getRoot())->key;//έχει αυτήν τη μορφή λόγο της υλοποίησης της συνάρτησης  minnode
                //χρησιμοποιείται το avltree.getRoot() ως παράμετρος καθώς στην υλοποίηση της ,η συνάρτηση,έχει παράμετρο node.
                //Επίσης χρησιμοποιείται το ->key γιατί η συνάρτηση επιστρέφει node ενώ εμείς θέλουμε int το οποίο στην προκειμένη περίπτωση
                //είναι το key του node
                output<<"\n";
            }
        }else if (value=="FINDMAX"){
            input>>value;
            if (value=="MINHEAP"){
                output<<"MINHEAP MAX:";
                output<<minheap.getMaxMin();
                output<<"\n";
            }else if (value=="MAXHEAP"){
                output<<"MAXHEAP MAX:";
                output<<maxheap.getMaxMin();
                output<<"\n";
            }
        }else if (value=="INSERT"){
            input>>value;
            if (value=="MINHEAP"){
                input>>num;
                minheap.insert(num);
                output<<"MINHEAP INSERT:";
                output<<num;
                output<<"\n";
            }else if (value=="MAXHEAP"){
                input>>num;
                maxheap.insert(num);
                output<<"MAXHEAP INSERT:";
                output<<num;
                output<<"\n";
            }else if (value=="AVLTREE"){
                input>>num;
                avltree.insert(num);
                output<<"AVLTREE INSERT:";
                output<<num;
            }else if (value=="GRAPH"){

            }else if (value=="HASHTABLE"){
                input>>num;
                hashtable.InsertItem(num);
                output<<"HASHTABLE INSERT:";
                output<<num;
            }
        }else if (value=="DELETEMIN") {
            input>>value;
            if (value=="MINHEAP") {
                output<<"MINHEAP DELETEMIN:";
                output<<minheap.deleteMaxMin();
                output<<"\n";
            }
        }else if (value=="DELETEMAX"){
            input>>value;
             if (value=="MAXHEAP"){
                output<<"MAXHEAP DELETEMAX:";
                output<<maxheap.deleteMaxMin();
                output<<"\n";
            }
        }else if (value=="SEARCH"){
            input>>value;
           if (value=="HASHTABLE"){
               input>>num;
               output<<"HASHTABLE SEARCH:";
               output<<hashtable.SearchItem(num);
               output<<"\n";
            }else if (value=="AVLTREE") {
                input>>num;
                output<<"AVLTREE SEARCH:";
                output<<avltree.Search(num);
                output<<"\n";
            }
        }else if (value=="DELETE"){
            input>>value;
            if (value=="GRAPH"){

            }else if (value=="AVLTREE") {
                input>>num;
                if (avltree.Delete(num)) {
                    output<<"AVLTREE DELETE:"<<num<<"SUCCESSFUL \n";
                }else {
                    output<<"AVLTREE DELETE:"<<num<<"FAILURE \n";
                }
            }
        }
    }
    input.close();
    output.close();
    return 0;
}