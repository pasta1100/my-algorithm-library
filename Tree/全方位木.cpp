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
#define INF 100000000

using mytuple = tuple<int, int, int>;
int mod = 998244353;

//https://ei1333.hateblo.jp/entry/2017/04/10/224413


int mxv = 1e5 + 9;
struct S{
    ll c;
    unsigned long long res;
    S(ll c = 0, ll r = 0): c(c), res(r){}
};

vvi G(mxv); //グラフ
ll csum = 0;    //木の総和
v<S> dat(mxv);  //データ配列

void add_edge(int s, int t){
    G[s].push_back(t);
    G[t].push_back(s);
}
//頂点sにおける木dp
void dfs1(int i = 0, int pre = -1){
    for(auto &j: G[i]){
        if(j == pre) continue;
        dfs1(j, i);

        //木dpの結合
        dat[i].c += dat[j].c;
        dat[i].res += dat[j].c + dat[j].res;
    }
}

//伝播
void dfs2(int i = 0, int pre = -1){
    for(auto &j: G[i]){
        if(j == pre) continue;
        
        //伝播処理
        dat[j].res = dat[i].res + csum - 2 * dat[j].c;
        dfs2(j, i);
    }
}

int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //ここから
    
    int n;
    cin >> n;

    rep(i, n - 1){
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    rep(i, n){
        ll c;
        cin >> c;
        dat[i] = S(c, 0);
        csum += c;
    }
    dfs1();
    dfs2();

    unsigned long long ans = dat[0].res;
    rep(i, n){
        chmin(ans, dat[i].res);
        //cerr << dat[i].res << sp;
    }
   // cerr << el;
    cout << ans << el;
}
