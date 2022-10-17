#include <bits/stdc++.h>
#include "RB_tree.h"
using namespace std;

void guardar(vector<pair<int,int>>& V, string dir)
{
    ofstream f(dir);
    for(auto a : V)
        f<<a.first<<' '<<a.second<<'\n';
    f.close();
}

int main()
{
    RB_Tree<int> RB;
    for(int i=1 ; i <= 20 ; ++i)
        RB.insert(i);
    RB.inOrder();
    RB.preOrder();
    RB.postOrder();
    cout<<RB.search(20)<<'\n';
    cout<<RB.search(1)<<'\n';
    RB.clear();
    // RB_Tree<int> RB;
    // vector<pair<int,int>> res;
    // int n = pow(10,2);
    // for( ; n<=10000 ; n+=100)
    // {
    //     srand(time(NULL));
    //     for(int j=n ; j>0 ; --j)
    //         RB.insert(j);
    //     //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior);
    //     int num = 1 + rand() % (n/10);
    //     // int num = 50;
    //     int comp = RB.search(num);
    //     res.push_back(make_pair(n,comp));
    //     // cout<<"valor buscado "<<num<<" tamanio "<<RB.getSize()<<" -> comparaciones "<<comp<<'\n';
    //     RB.clear();
    // }
    // guardar(res,"data.txt");
}