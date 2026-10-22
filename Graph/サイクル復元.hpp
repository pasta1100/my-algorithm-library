#include <bits/stdc++.h>
using namespace std;

//有向
vector<vector<int>> G;
vector<int> st, par;
vector<int> cycle;

bool dfs(int v){
    st[v] = 1;
    for(int nv : G[v]){
        if(st[nv] == 0){
            par[nv] = v;
            if(dfs(nv)) return true;
        }else if(st[nv] == 1){
            // サイクル復元
            cycle.push_back(nv);
            for(int x = v; x != nv; x = par[x]){
                cycle.push_back(x);
            }
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    st[v] = 2;
    return false;
}

vector<int> get_cycle(int n){
    st.assign(n, 0);
    par.assign(n, -1);
    cycle.clear();

    for(int i = 0; i < n; i++){
        if(st[i] == 0 && dfs(i)){
            return cycle;
        }
    }
    return {};
}

//無向
vector<vector<int>> G;
vector<int> vis, par;
vector<int> cycle;

bool dfs(int v, int p){
    vis[v] = 1;
    for(int nv : G[v]){
        if(nv == p) continue;

        if(!vis[nv]){
            par[nv] = v;
            if(dfs(nv, v)) return true;
        }else{
            // サイクル復元
            cycle.push_back(nv);
            for(int x = v; x != nv; x = par[x]){
                cycle.push_back(x);
            }
            return true;
        }
    }
    return false;
}

vector<int> get_cycle(int n){
    vis.assign(n, 0);
    par.assign(n, -1);
    cycle.clear();

    for(int i = 0; i < n; i++){
        if(!vis[i] && dfs(i, -1)){
            return cycle;
        }
    }
    return {};
}