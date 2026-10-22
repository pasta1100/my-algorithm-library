#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
template <class S> using vvv = vector<vector<vector<S>>>;
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

//二乗の木dp
//完全グラフになるように合成すると，Knの変数に依存するため，O(N^2)となる
//部分グラフの根に，childを合成するとき，
//現在の部分グラフのsizeと，childのsizeのみで2重ループを回す
//https://snuke.hatenablog.com/entry/2019/01/15/211812
//https://atcoder.jp/contests/abc287/tasks/abc287_f

const int mod = 998244353;
// const int mod = 1e9 + 7;

void add_edge(int s, int t, vector<vector<int>> &G){
    G[s].push_back(t);
    G[t].push_back(s);
}

int mxv = 5001;
vvi G(mxv);
//node, num, mystate
vvv<ll> dp(mxv, vvll(2, vll(2)));

vi siz(mxv, 1);
void merge(int a, int b){ //par:a, cil b
    vvll ndp(siz[a] + siz[b] + 1, vll(2));
    rep(i, siz[a] + 1){
        rep(j, siz[b] + 1){
            ndp[i + j][0] += dp[a][i][0] * ((dp[b][j][1] + dp[b][j][0]) % mod) % mod;  
            ndp[i + j][1] += dp[a][i][1] * dp[b][j][0] % mod;   
            if(i + j - 1 >= 0) ndp[i + j - 1][1] += dp[a][i][1] * dp[b][j][1] % mod;   
             
            ndp[i + j][0] %= mod;
            ndp[i + j][1] %= mod;
            if(i + j - 1 >= 0) ndp[i + j - 1][1] %= mod;
        }
    }
    swap(dp[a], ndp);
    siz[a] += siz[b];
}

//頂点sにおける木dp
void dfs(int i = 0, int pre = -1){
    for(auto j: G[i]){
        if(j == pre) continue;
        dfs(j, i);

        //木dpの結合
        merge(i, j);
    }

}
int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    //ここから

    int n; cin >> n;
    rep(i, n - 1){
        int a, b; cin >> a >> b;
        add_edge(a - 1, b - 1, G);
    }
    rep(i, n){
        dp[i][0][0] = 1;
        dp[i][1][1] = 1;
    }
    dfs();
    rep(i, 1, n + 1){
        cout << (dp[0][i][0] + dp[0][i][1]) % mod << el;
    }
}
/*
cppt
cppt_ge
seg, bit, uf

g++ main.cpp -O2 -std=c++17
./a.out

*/