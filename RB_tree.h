#ifndef RB_TREE
#define RB_TREE

#include <fstream>
#include <iostream>
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
    void leftRotation(Node<T>* N);
    void rightRotation(Node<T>* N);
public:
    RB_Tree():root(nullptr),size(0){}
    ~RB_Tree();
    void insert(T v);                               
    void insertFixup(Node<T>*& N);                  
    void inOrder();
    void postOrder();
    void preOrder();
    int search(T v);                    // devuelve la cantidad de comparaciones hasta encontrar
    void clear();
    int getSize(){ return size; }
    void graficar(std::string dir); 
};

template<typename T>
RB_Tree<T>::~RB_Tree()
{
    root->autoMatate(root);     // recursivo
                                // falta iterativo
    // std::cout<<"murio\n";
}

template<typename T>
void RB_Tree<T>::inOrder()
{
    inOrder( root );
    std::cout<<'\n';
}

template<typename T>
void RB_Tree<T>::inOrder( Node<T>*& N )
{
    if( !N ) return;
    inOrder( N->pSon[0] );
    std::cout<<N->value<<' ';
    inOrder( N->pSon[1] );
}

template<typename T>
void RB_Tree<T>::preOrder()
{
    preOrder( root );
    std::cout<<'\n';
}

template<typename T>
void RB_Tree<T>::preOrder( Node<T>*& N )
{
    if( !N ) return;
    std::cout<<N->value<<' ';
    preOrder( N->pSon[0] );
    preOrder( N->pSon[1] );
}

template<typename T>
void RB_Tree<T>::postOrder()
{
    postOrder( root );
    std::cout<<'\n';
}

template<typename T>
void RB_Tree<T>::postOrder( Node<T>*& N )
{
    if( !N ) return;
    postOrder( N->pSon[0] );
    postOrder( N->pSon[1] );
    std::cout<<N->value<<' ';
}

template<typename T>
void RB_Tree<T>::leftRotation(Node<T>* N) 
{
    Node<T>* y = N -> pSon[1];
    N -> pSon[1] = y -> pSon[0];
    
    if(y -> pSon[0]) (y -> pSon[0]) -> pSon[2] = N;
    y -> pSon[2] = N -> pSon[2];
    
    if(!(N -> pSon[2])) // si N es raiz 
        root = y; 
    else if(N == ((N -> pSon[2]) -> pSon[0])) // si es hijo izquierdo 
        (N -> pSon[2]) -> pSon[0] = y;
    else                                      // si es hijo derecho 
        (N -> pSon[2]) -> pSon[1] = y;

    y -> pSon[0] = N;
    N -> pSon[2] = y;
}

template<typename T>
void RB_Tree<T>::rightRotation(Node<T>* N) 
{
    Node<T>* y = N -> pSon[0];
    N -> pSon[0] = y -> pSon[1];

    if(y -> pSon[1]) (y -> pSon[1]) -> pSon[2] = N;
    y -> pSon[2] = N -> pSon[2];
    
    if(!(N -> pSon[2])) // si N es raiz 
        root = y; 
    else if(N == ((N -> pSon[2]) -> pSon[0])) // si es hijo izquierdo 
        (N -> pSon[2]) -> pSon[0] = y;
    else                                      // si es hijo derecho 
        (N -> pSon[2]) -> pSon[1] = y;

    y -> pSon[1] = N;   
    N -> pSon[2] = y;    
}

template<typename T>
void RB_Tree<T>::insert(T v)
{
    Node<T>* z = new Node<T>(v);
    Node<T>* y = nullptr;
    Node<T>* x = root;
    while(x)
    {
        y = x;
        if(z->value < x->value)
            x = x->pSon[0];
        else
            x = x->pSon[1];
    }
    z->pSon[2] = y;
    if(!y)
        root = z;
    else if(z->value < y->value)
        y->pSon[0] = z;
    else
        y->pSon[1] = z;
    z->pSon[0] = nullptr;
    z->pSon[1] = nullptr;
    z->col = 1;
    insertFixup(z);
    size++;
}

template <typename T>
void RB_Tree<T>::insertFixup(Node<T>* &a){
    Node<T> *y; // Tio
    while(a->pSon[2] && a->pSon[2]->col)
    {
        if(a->pSon[2]->pSon[2] && a->pSon[2] == a->pSon[2]->pSon[2]->pSon[0])
        {
            y = a->pSon[2]->pSon[2]->pSon[1]; //Tio derecho
            if(y && y->col)         // existe tio y es rojo
            {
                y->col = 0;
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                a = a->pSon[2]->pSon[2];
            }   
            else
            {
                if(a == a->pSon[2]->pSon[1])
                {
                    a = a->pSon[2];
                    leftRotation(a);
                }
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                rightRotation(a->pSon[2]->pSon[2]);
            }
        }
        else if(a->pSon[2]->pSon[2] && a->pSon[2] == a->pSon[2]->pSon[2]->pSon[1])
        {
            y = a->pSon[2]->pSon[2]->pSon[0]; //Tio iszquierdo
            if(y && y->col)
            {   
                y -> col = 0;
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                a = a->pSon[2]->pSon[2];
            }
            else
            {
                if(a == a->pSon[2]->pSon[0])
                {
                    a = a->pSon[2];
                    rightRotation(a);
                }
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                leftRotation(a->pSon[2]->pSon[2]);
            }
        }
        // if(a==root) break;
    }
    root->col = 0;
}

template<typename T>
int RB_Tree<T>::search(T v)
{
    Node<T>* tmp = root;
    int c=0;
    while(tmp)
    {
        c++;
        if(tmp->value == v)
            return c;
        if(v < tmp->value)
            tmp = tmp->pSon[0];
        else
            tmp = tmp->pSon[1];
    }
    return -1;
}

template<typename T>
void RB_Tree<T>::clear()
{
    root->autoMatate(root);
    size = 0;
    root = nullptr;
    // std::cout<<"murio\n";
}

#endif