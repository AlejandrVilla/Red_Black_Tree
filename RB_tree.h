#ifndef RB_TREE
#define RB_TREE

#include <fstream>
#include "node.h"

template<typename T>
class RB_Tree
{
private:
    Node<T>* root;
    int size;

    void inOrder(Node<T>*& N);
    void preOrder(Node<T>*& N);
    void postOrder(Node<T>*& N);
    void graficar(Node<T>*& N, std::ofstream& f);
    void leftRotation(Node<T>*& N);
    void rightRotation(Node<T>*& N);
public:
    RB_Tree():root(nullptr),size(0){}
    ~RB_Tree();
    void insert(T v);
    void insertFixup(Node<T>*& N);
    void inOrder();
    void postOrder();
    void preOrder();
    void search(T v);
    void graficar(std::string dir);
};

template<typename T>
RB_Tree<T>::~RB_Tree()
{
    root->autoMatate(root);     // recursivo
                                // falta iterativo
}

#endif