#include <bits/stdc++.h>
using namespace std;

template<class S>struct CartesianTree{
    int root; //root
    vector<int> par, left, right;
    CartesianTree() : root(0){}
    CartesianTree(const vector<S> & v):root(0), par(v.size(), -1), left(v.size(). -1), right(v.size(), -1){
        vector<int> st(v.size(), 0);
        int top = 0;
        for(int i = 1, i < v.size(); ++i){
            if(v[st[top]] > v[i]){
                while(top >= 1 && v[st[top - 1]] > v[i]) --top;
                left[i] = st[top];
                par[left[i]] = i;
                if(top == 0){
                    root = i;
                }else{
                    par[i] = st[top - 1];
                    right[par[i]] = i;
                }
            }else{
                par[i] = st[top];
                right[par[i]] = i;
                st[++top] = i;
            }
        }
    }
};

int main(){

}

/*
g++ main.cpp -O2 -std=c++17
./a.out

*/