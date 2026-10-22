/*
My competitive programming library
Source:https://github.com/pasta1100/my-algorithm-library
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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

int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    //ここから

    
}
/*
cppt
cppt_ge
seg, bit, uf

g++ main.cpp -O2 -std=c++17
./a.out

*/