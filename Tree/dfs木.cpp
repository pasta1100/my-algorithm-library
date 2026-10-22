#include <bits/stdc++.h>
using namespace std;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
template <class S> using vvv = vector<vector<vector<S>>>;
#define vi vector<int>
#define vvi vector<vector<int>>
const int INF = 1e9;

/*

Gから構築したdfs木をT1とすると，
・T1に含まれないすべてのGの辺{u,v}について 
"uとvが祖先と子孫の関係"にある
・(木辺と逆辺のみで横断辺は存在しない)

→この"辺"から，多重辺を認めない限り，u,vの距離は2以上離れていることがわかる

・一般に形状は唯一とは限らない
*/

//双方向辺
void add_edge(int s, int t, vector<vector<int>> &G){
    G[s].push_back(t);
    G[t].push_back(s);
}
// dfs木構築:dfsG, ノードの深さ:depth, s:根
void dfs(const vvi& G, vvi &dfsG, vi &depth, int s = 0, int prev = -1){
    if(prev == -1){//初期化
        dfsG.assign(G.size(), vi());
        depth.assign(G.size(), INF);
        depth[s] = 0;
    }
    for(int t: G[s]){
        if(t == prev) continue;
        if(depth[t] == INF){
            dfsG[s].push_back(t);
            depth[t] = depth[s] + 1;
            dfs(G, dfsG, depth, t, s);
        }
    }
}