#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define sp ' '
#define Yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl
template<class S>
bool chmin(S &a, const S &b){
    if (b < a){ a = b; return true; }
    return false;
}
template<class S>
bool chmax(S &a, const S &b){
    if (b > a){ a = b; return true; }
    return false;
}

#define INF 1000000000


int mxv = 2000;

int V;
struct edge{ int to, cap, cost, rev;};
vv<edge> G(mxv);
vi dist(mxv);
vi prevv(mxv), preve(mxv);

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    while(f > 0){
        //ベルマンフォード法で最短路を求める
        dist.assign(mxv, INF);
        dist[s] = 0;
        bool upd = true;
        while(upd){
            upd = false;
            rep(i, V){
                if(dist[i] == INF) continue;
                rep(j, G[i].size()){
                    auto &[to, cap, cost, rev] = G[i][j];
                    if(cap > 0 && dist[to] > dist[i] + cost){
                        dist[to] = dist[i] + cost;
                        prevv[to] = i;
                        preve[to] = j;
                        upd = true;
                    }
                }
            }
        }

        if(dist[t] == INF){
            //流すことができない
            return -1;
        }

        //s-t最短路に目一杯流す
        int d = f;
        for(int i = t; i != s; i = prevv[i]){
            d = min(d, G[prevv[i]][preve[i]].cap);
        }
        f -= d;
        res += d * dist[t];
        
        for(int i = t; i != s; i = prevv[i]){
            auto &[to, cap, cost, rev] = G[prevv[i]][preve[i]];
            cap -= d;
            G[i][rev].cap += d;
        }
    }
    return res;
}
int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //ここから

}
/*

g++ main.cpp -O2 -std=c++17
./a.out

*/