#ifndef NODE
#define NODE

template<typename T>
class Node
{
private:
public:
    T value;
    Node<T>* pSon[3];       // izq, der, padre
    bool col;               // color 0 negro, 1 rojo
    Node(T v);
    void autoMatate(Node<T>* N);
};

template<typename T>
Node<T>::Node(T v)
{
    value = v;
    pSon[0] = pSon[1] = pSon[2] = 0;
    col = 0;
}

template<typename T>
void Node<T>::autoMatate(Node<T>* N)
{
    if(!N) return;
    // std::cout<<"hola\n";
    autoMatate(N->pSon[0]);
    autoMatate(N->pSon[1]);
    delete N;
}

#endif