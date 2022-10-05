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
    void leftRotation(Node<T>*& N) {
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
    void rightRotation(Node<T>*& N) {
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
    root->autoMatate(root);     // recursivo
                                // falta iterativo
}



#endif