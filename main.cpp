#include <iostream>
#include <math.h>
#include "RB_tree.h"
using namespace std;

int main()
{
    RB_Tree<int> RB;
    int n = pow(10,1);
    for(int i=n ; i>0 ; --i)
        RB.insert(i);
    RB.inOrder();
    RB.preOrder();
    RB.postOrder();
}