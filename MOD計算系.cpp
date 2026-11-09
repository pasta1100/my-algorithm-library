#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vi vector<int>

int mod = 998244353;

//a^x mod(p)
int mod_pow(ll a, ll x){
    a %= mod;
    if(a == 0){
        if(x == 0) return 1;
        return 0;
    }
    int res = 1;
    while(x){
        if(x & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

// F!, nCk, nPk
struct Comb {
    vector<ll> fact, invfact;

    Comb(int n){
        fact.resize(n+1);
        invfact.resize(n+1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++){
            fact[i] = fact[i-1] * i % mod;
        }
        invfact[n] = mod_pow(fact[n], mod-2);
        for(int i = n-1; i >= 0; i--){
            invfact[i] = invfact[i+1] * (i+1) % mod;
        }
    }

    ll C(int n, int k){
        if(k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % mod * invfact[n-k] % mod;
    }

    ll P(int n, int k){
        if(k < 0 || k > n) return 0;
        return fact[n] * invfact[n - k] % mod; 
    }
};

//nCi = res[i]として組合せ計算
vi nCk_all(int n){
    vi res(n + 1, 1), inv(n + 1, 1);
    // 1〜n の逆元をすべて O(N) で計算する有名なアルゴリズム
    for (int i = 2; i <= n; i++) {
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
    }
    for(int i = 1; i <= n; i++){
        res[i] = (ll) res[i - 1] * (n - i + 1) % mod;
        res[i] = (ll) res[i] * inv[i] % mod;
    }
    return res;
}

//逆元計算
int inv(ll a){
    a %= mod;
    int p = mod - 2;
    int res = 1;
    while(p){
        if(p & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

vi calc_inv(int n, int md = mod){
    vi inv(n + 1, 1);
    // 1〜n の逆元をすべて O(N) で計算する有名なアルゴリズム
    for (int i = 2; i <= n; i++) {
        inv[i] = (ll)(md - md / i) * inv[md % i] % md;
    }
    return inv;
}

int main(){

}