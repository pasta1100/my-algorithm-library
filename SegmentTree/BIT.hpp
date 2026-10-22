#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n) : n(n), bit(n + 1, 0) {}
    // A[i] += x
    void add(int i, long long x){
        for(i++; i <= n; i += i & -i){
            bit[i] += x;
        }
    }
    // [0, r)
    long long sum(int r){
        long long s = 0;
        for(; r > 0; r -= r & -r){
            s += bit[r];
        }
        return s;
    }
    //[l, r)
    long long sum(int l, int r){
        return sum(r) - sum(l);
    }
};


//転倒数
long long inversion_count(vector<int> &a){
    int n = a.size();
    int mx = *max_element(a.begin(), a.end());
    BIT bit(mx + 1);
    long long res = 0;

    for(int i = 0; i < n; i++){
        // a[i]より大きい要素の個数
        res += i - bit.sum(a[i]);
        bit.add(a[i], 1);
    }
    return res;
}
// //配列 s,tのswap差(転倒数)
// map<int,int> pos;
// rep(i, l) pos[s[i]] = i;
// vi a(l);
// rep(i, l) a[i] = pos[t[i]];
// ll inv = inversion_count(a);