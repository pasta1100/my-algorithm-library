#include <bits/stdc++.h>
using namespace std;
template <class S> using v = vector<S>;

template<typename S, S(*op)(S, S)>
struct SegmentTree{
    int n;
    S e;
    v<S> dat;
    SegmentTree(int _n, S e):e(e){
        n = 1;
        while(n < _n) n *= 2;
        dat.assign(2 * n, e);
    }

    void set(int p, S x){
        p += n;
        dat[p] = x;
        while(p > 1){
            p /= 2;
            dat[p] = op(dat[p * 2], dat[p * 2 + 1]);
        }
    }
    S prod(int a, int b, int k = 1, int l = 0, int r = -1){
        if(r == -1) r = n;
        if(r <= a || b <= l) return e;
        if(a <= l && r <= b) return dat[k];
        return op(prod(a, b, k * 2, l, (l + r) / 2), prod(a, b, k * 2 + 1, (l + r) / 2, r));
    }
    S get(int i){return dat[n + i];}
};

