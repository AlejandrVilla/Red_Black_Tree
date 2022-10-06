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
    void insert(T v);                               // implementar
    void insertFixup(Node<T>*& N);                  // implementar
    void inOrder();
    void postOrder();
    void preOrder();
    void search(T v);
    void graficar(std::string dir); 
};

template<typename T>
RB_Tree<T>::~RB_Tree()
{
    //root->autoMatate(root);     // recursivo
                                // falta iterativo
}

template<typename T>
void RB_Tree<T>::leftRotation(Node<T>*& N) 
{
    Node<T> * y = N -> pSon[1];
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
void RB_Tree<T>::rightRotation(Node<T>*& N) 
{
    Node<T> * y = N -> pSon[0];
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
}

template <typename T>
void RB_Tree<T>::insertFixup(Node<T>* &a){
    Node<T> *y; // Tio
    while((a->pSon[2])->col){
        if(a->pSon[2] == a->pSon[2]->pSon[2]->pSon[0]){
            y = a->pSon[2]->pSon[2]->pSon[1]; //Tio derecho
            if(y->col){
                y->col = 0;
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                a = a->pSon[2]->pSon[2];
            }else{
                if(a == a->pSon[2]->pSon[1]){
                    a = a->pSon[2];
                    leftRotation(a);
                }
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                rightRotation(a->pSon[2]->pSon[2]);
            }
        }else{
            y = a->pSon[2]->pSon[2]->pSon[0]; //Tio iszquierdo
            if(y->col){
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                a = a->pSon[2]->pSon[2];
            }else{
                if(a == a->pSon[2]->pSon[0]){
                    a = a->pSon[2];
                    rightRotation(a);
                }
                a->pSon[2]->col = 0;
                a->pSon[2]->pSon[2]->col = 1;
                leftRotation(a->pSon[2]->pSon[2]);
            }
        }
        if(a==root) break;
    }
    root->col = 0;
}

#endif