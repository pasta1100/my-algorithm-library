#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
#define rep(...) overload_rep(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define overload_rep(_1, _2, _3, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
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
template<class T>
bool chmin(T &a, const T &b){
    if (b < a){ a = b; return true; }
    return false;
}
template<class T>
bool chmax(T &a, const T &b){
    if (b > a){ a = b; return true; }
    return false;
}

using mtup = tuple<int, int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const int mod = 998244353;
// const int mod = 1e9 + 7;

//2dfsで直径の端点
int far = 0;
// 幅優先探索
vector<int> bfs(const vector<vector<int>>& G, int s){
    int n = G.size();
    vector<int> res(n, -1); res[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int i = que.front(); que.pop(); far = i;
        for(auto &j : G[i]){
            if(res[j] == -1){
                res[j] = res[i] + 1;
                que.push(j);
            }
        }
    }
    return res;
}
//ダブリングで2^nパスを生成
void dfs(vvi& par, vvi& G, int i, int p = -1){
    for(auto &j: G[i]){
        if(j == p) continue;
        par[j][0] = i;
        rep(k, 20){
            if(par[par[j][k]][k] == -1) break;
            par[j][k + 1] = par[par[j][k]][k]; 
        }
        dfs(par, G, j, i);
    }
}
vvi f(vvi& G, int s){
    vvi par(G.size(), vi(20, -1));
    dfs(par, G, s);
    return par;
}

int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    //ここから

    int n; cin >> n;
    vvi G(n);
    rep(i, n - 1){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(G, 0);int s = far;
    //s-t直径
    vi d1 = bfs(G, s);int t = far;
    vi d2 = bfs(G, t);
    vvi par1 = f(G, s);
    vvi par2 = f(G, t);
    int q; cin >> q;
    rep(i, q){
        int u, k; cin >> u >> k;
        u--;
        if(max(d1[u], d2[u]) < k) {cout << -1 << el; continue;}
        if(d1[u] > d2[u]){
            rep(j, 20){
                if((k >> j) & 1){
                    u = par1[u][j];
                }
            }
        }else{
            rep(j, 20){
                if((k >> j) & 1){
                    u = par2[u][j];
                }
            }
        }
        cout << u + 1 << el;
    }
}