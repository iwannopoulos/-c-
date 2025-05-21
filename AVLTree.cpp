#include "AVLTree.h"
#include <iostream>
#include <algorithm>
using namespace std;
// εισαγωγη στοιχειων απο filename.txt*
//1.πληθοσ στοιχειων*
//2.ευρεση ελαχιστου στοιχειου
//3.ευρεση στοιχειου*
//4.εισαγει τον  αριθμο number?(γινεται απο την main)
//5.διαγραφη στοιχειου*
AVLTree::Node::Node()
{
    // :)
}

AVLTree::Node::Node(int key)
{
    this->key=key;
    l=nullptr;
    r=nullptr;
    h=1;
}
int AVLTree::Node::getKey() const{
    return key;
}
AVLTree::Node* AVLTree::Node::getLeft() const{
    return l;
}
AVLTree::Node* AVLTree::Node::getRight() const{
    return r;
}
int AVLTree::Node::getHeight() const{
    return h;
}
void AVLTree::Node::setKey(int key)
{
    this->key=key;
}
void AVLTree::Node::setLeft(Node *left)
{
    l=left;
}
void AVLTree::Node::setRight(Node *right)
{
    r=right;
}
void AVLTree::Node::setHeight(int height)
{
    h=height;
}

AVLTree::AVLTree()
{
    root=nullptr;
}


int AVLTree::height(Node *node)
        {
            if(node==nullptr)
            {
                return 0;
            }
            return node->h;
        }
int AVLTree::getBalance(Node *node)
        {
            if(node==nullptr)
            {
                return 0;
            }
            return height(node->l)-height(node->r);
        }
        //dejia peristroph
AVLTree::Node * AVLTree::rightRotate(Node *y)
        {
            Node *x=y->l;
            Node *T2=x->r;
    
            x->r=y;
            y->l=T2;
            
            //uptade height
            y->h=1+max(height(y->l),height(y->r));
            x->h=1+max(height(x->l),height(x->r));
            return x;
        }
        //aristerh peristroph
AVLTree::Node * AVLTree::leftRotate(Node *x)
        {
           Node *y=x->r;
           Node *T2=y->l;
           y->l=x;
           x->r=T2;
           x->h=1+max(height(x->l),height(x->r));
           y->h=1+max(height(y->l),height(y->r));
           return y;
           
        }
AVLTree::Node *AVLTree::insert(Node *node,int key)
        {
            if(node==nullptr)
            {
                return new Node(key); //?
            }
            if(key<node->key)
            {
                node->l=insert(node->l,key);
            }
            else if(key >node->key)
            {
                node->r=insert(node->r,key);
            }
            else
            {
                return node;
            }
                    node->h=1+max(height(node->l),height(node->r));
                    int balance=getBalance(node);
                    //αριστερη αριστερη 
                    if(balance>1 && key<node->l->key)
                    {
                        return rightRotate(node);
                    }
                // δεξια δεξια 
            if(balance<-1 && key>node->r->key)
            {
                return leftRotate(node);
            }
            //αριστερη δεξια 
            if(balance>1 &&key>node->l->key)
            {
                node->l=leftRotate(node->l);
                return rightRotate(node);
            }
            //δεξια αριστερη
            if (balance<-1 && key<node->r->key)
            {
                node->r=rightRotate(node->r);
                return leftRotate(node);
            }
            return node;
        }
void AVLTree::insert(int key)
{
    root=insert(root,key);
}
int AVLTree::countNodes(Node *node)
{
    if(node==nullptr)
    {
        return 0;
    }
    return 1+countNodes(node->l)+countNodes(node->r);
}
int AVLTree::size()
{
    return countNodes(root);
}
string AVLTree::Search(int number)
{
    Node *p=root;
    while(p!=nullptr)
    {
        if(number<p->key)
        {
            p=p->l;
        }
        else if(number>p->key)
        {
            p=p->r;
        }
        else
            return "SUCCESS";
    }
    return "FAILURE";
}
void AVLTree::Delete(int number)
{
    // Βρίσκουμε τον κόμβο προς διαγραφ
    if(Search(number)=="FAILURE")
         return;
    Node *p = root;
    Node *pp = nullptr;  // Γονέας του κόμβου που θέλουμε να διαγράψουμε
    while (p && p->key !=number)
    {
        pp=p;
        if (number<p->key)
        {
            p=p->l;
        }
        else
        {
            p=p->r;
        }
    }
    // Αν ο κόμβος έχει δύο παιδιά (τότε θα βρούμε τον προκάτοχο ή επικείμενο)
    if (p->l && p->r)
    {
        Node *s=p->l;
        Node *ps=p;  // Ο γονέας του προκάτοχου
        while (s->r)  // Βρίσκουμε τον μεγαλύτερο κόμβο από το αριστερό υποδέντρο
        {
            ps=s;
            s=s->r;
        }
        
        // Αντικαθιστούμε το key του κόμβου προς διαγραφή με τον προκάτοχο
        p->key=s->key;

        // Διαγράφουμε τον προκάτοχο (το νέο p)
        p=s;
        pp=ps;
    }
    // Αν ο κόμβος έχει 0 ή 1 παιδί
    Node *c=nullptr;
    if (p->l)
    {
        c=p->l;
    }
    else
    {
        c=p->r;
    }

    // Αν ο κόμβος προς διαγραφή είναι η ρίζα
    if (p==root)
    {
        root=c;
    }
    else
    {
        // Αλλιώς, ενημερώνουμε τον γονέα του κόμβου
        if (p==pp->l)
        {
            pp->l=c;
        }
        else
        {
            pp->r=c;
        }
    }
    // Διαγράφουμε τον κόμβο
    delete p;
    // Ενημερώνουμε ύψη και επαναφέρουμε την ισορροπία (αν χρειάζεται)
    Rebalance(pp);
}

void AVLTree::Rebalance(Node* node)
{
    // Αναδρομή για να ελέγξουμε το δέντρο από κάτω προς τα πάνω
    while(node)
    {
        node->h=1+max(height(node->l),height(node->r));
        int balance=getBalance(node);
        // Έλεγχος για περιστροφές
        if (balance>1)
        {
            if (getBalance(node->l)>=0)
            {
                node=rightRotate(node);
            }
            else
            {
                node->l=leftRotate(node->l);
                node=rightRotate(node);
            }
        }
        else if (balance<-1)
        {
            if (getBalance(node->r)<=0)
            {
                node=leftRotate(node);
            }
            else
            {
                node->r=rightRotate(node->r);
                node=leftRotate(node);
            }
        }
 // Πηγαίνουμε στον γονέα του κόμβου
        node=(node==root) ? nullptr:node->l;
    }
}
AVLTree::Node* AVLTree::minnode(Node* node)
{
    if(node==nullptr || node->l==nullptr)
    {
        return node;
    }
    return minnode(node->l);
}
AVLTree::Node* AVLTree::getRoot() {
    return root;
}



