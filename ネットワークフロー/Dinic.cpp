#include <bits/stdc++.h>
using namespace std;

//Dinicは通常O(N^2M),二部マッチO(N√M)
//ここから

const int INF = 1e9;
int mxv = 2000;
struct edge{ int to, cap, rev;};
vector<vector<edge>> G(mxv);
vector<int> level(mxv), iter(mxv);

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}
// sからの最短距離
void bfs(int s){
    fill(level.begin(), level.end(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int p = que.front(); que.pop();
        for(auto [to, cap, rev]: G[p]){
            if(cap > 0 && level[to] < 0){
                level[to] = level[p] + 1;
                que.push(to);
            }
        }
    }
}

int dfs(int s, int t, int f){
    if(s == t) return f;
    for(int &i = iter[s]; i < G[s].size(); i++){
        auto &[to, cap, rev] = G[s][i];
        if(cap > 0 && level[s] < level[to]){
            int d = dfs(to, t, min(f, cap));
            if(d > 0){
                cap -= d;
                G[to][rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        iter.assign(mxv, 0);
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}




int main(){
    
}

/*
g++ main.cpp -O2 -std=c++17
./a.out

*/