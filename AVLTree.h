#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
class AVLTree
{
    public:
        struct Node
        {
            int key;
            Node *l;
            Node *r;
            int h;
            Node();
            Node(int key);
            int getKey() const;
            Node* getLeft() const;
            Node* getRight() const;
            int getHeight() const;
            void setKey(int key);
            void setLeft(Node* left);
            void setRight(Node* right);
            void setHeight(int height);
        };
    private:
        Node *root;
        int height(Node *node);
        int getBalance(Node *node);
        Node* rightRotate(Node *y);
        Node* leftRotate(Node *x);
        Node* insert(Node *node,int key);
    public:
          AVLTree();
          void insert(int key);
          int countNodes(Node *node);
          int size();
          std::string Search(int number);
          void Delete(int number);
          void Rebalance(Node *node);
          Node* minnode(Node *node);
          Node* getRoot();

          
};

#endif
