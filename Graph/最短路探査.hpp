#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
template<class S>
bool chmin(S &a, const S &b){
    if (b < a){ a = b; return true; }
    return false;
}
const int INF = 1e9;
const long LINF = 1e9;

void add_edge(int s, int t, vector<vector<int>> &G){
    G[s].push_back(t);
    G[t].push_back(s);
}
// 幅優先探索
vector<int> bfs(const vector<vector<int>>& G, int s){
    int n = G.size();
    vector<int> res(n, INF); res[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int i = que.front(); que.pop();
        for(auto &j : G[i]){
            if(res[j] == INF){
                res[j] = res[i] + 1;
                que.push(j);
            }
        }
    }
    return res;
}

void add_edge(int s, int t, long long w, vv<pii> &G){
    G[s].push_back({t, w});
    G[t].push_back({s, w});
}
//ダイクストラ 
vll dijkstra(const vv<pii>& G, int s){
    int n = G.size();
    vll dist(n, LINF); 
    priority_queue<pll, v<pll>, greater<pll>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto [w, p] = pq.top();
        pq.pop();
        if(dist[p] < w) continue;
        dist[p] = w;
        for(auto &[to, wei]: G[p]){
            if(dist[to] > dist[p] + wei){
                dist[to] = dist[p] + wei;
                pq.push({dist[to], to});
            }
        }
    }  
    return dist;
}

//ワーシャルフロイド法
void Floyd_Warshall(vv<ll>& dist){
    int n = dist.size();
    rep(i, n){
        rep(j, n){
            rep(k, n){
                chmin(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

//ベルマンフォード法
using Edge = tuple<int, int, int>;
bool BellmanFord(const v<Edge>& E, int s, vll& res){
    int n = E.size();
    res.assign(n, 1e18); res[s] = 0;
    rep(i, n + 1){
        bool upd = false;
        for(auto &[t, u, w]: E){
            if(res[u] > res[t] + w){
                upd = true;
                res[u] = res[t] + w;
            }
        }
        if(!upd) return true;
        if(i == n) return false;
    }
}

int main(){


}
/*

g++ main.cpp -O2 -std=c++17
./a.out

*/