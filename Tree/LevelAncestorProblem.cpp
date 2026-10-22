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

//stackを用いたLevel Ancestor Problem 
vi ans;
vi a;//stack
void dfs(vvi& G, vv<pii>& q, int i, int p = -1){
    for(auto &[id, k]: q[i]){
        if((int)a.size() - k >= 0){ans[id] = a[a.size() - k] + 1;}
    }
    a.push_back(i);
    for(auto &j: G[i]){
        if(j == p) continue;
        dfs(G, q, j, i);
    }
    a.pop_back();
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
    bfs(G, s);int t = far;
    int q; cin >> q;
    vv<pii> qur(n);
    rep(i, q){
        int u, k; cin >>u >> k;
        qur[u - 1].push_back({i, k});
    }
    ans.assign(q, -1);
    dfs(G, qur, s);
    dfs(G, qur, t);
    rep(i, q) cout << ans[i] << el;
}
/*
cppt
cppt_ge
seg, bit, uf

g++ main.cpp -O2 -std=c++17
./a.out

*/