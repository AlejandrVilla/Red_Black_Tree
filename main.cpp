#include <iostream>
#include <math.h>
#include "RB_tree.h"
using namespace std;

int main()
{
    RB_Tree<int> RB;
    for(int i=1 ; i<pow(10,5) ; i++)
        RB.insert(i);
    // RB.inOrder();
    // RB.preOrder();
    // RB.postOrder();
}