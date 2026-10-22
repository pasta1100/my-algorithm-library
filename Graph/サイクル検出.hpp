#include <bits/stdc++.h>
using namespace std;

//有向グラフ
//サイクルがあるかYes/No
bool dfs(int v, const vector<vector<int>>& G, vector<int>& st){
    st[v] = 1;
    for(int nv : G[v]){
        if(st[nv] == 0){
            if(dfs(nv, G, st)) return true;
        }else if(st[nv] == 1){
            return true;
        }
    }
    st[v] = 2;
    return false;
}
bool has_cycle(const vector<vector<int>>& G){
    int n = G.size();
    vector<int> st(n, 0);

    for(int i = 0; i < n; i++){
        if(st[i] == 0){
            if(dfs(i, G, st)) return true;
        }
    }
    return false;
}

//グローバル版
const int N = 2e5 + 9;
vector<vector<int>> G(N);
vector<int> st(N);

bool dfs(int v){
    st[v] = 1;
    for(int nv : G[v]){
        if(st[nv] == 0){
            if(dfs(nv)) return true;
        }else if(st[nv] == 1){
            return true;
        }
    }
    st[v] = 2;
    return false;
}

bool has_cycle(int n){
    st.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(st[i] == 0){
            if(dfs(i)) return true;
        }
    }
    return false;
}

// //無向グラフ
// UnionFind uf(n);
// bool has_cycle = false;

// for(auto [u, v] : edges){
//     if(!uf.unite(u, v)){
//         has_cycle = true;
//     }
// }