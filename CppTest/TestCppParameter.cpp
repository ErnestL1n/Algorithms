/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


void dfs(int& res,int k=8){
    if(k<10){
        dfs(++res,++k);
    }
}


int main()
{
    int res=0;
    dfs(res,5);
    cout << res <<"\n";
    return 0;
}

