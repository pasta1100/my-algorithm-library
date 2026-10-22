#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S> using v = vector<S>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>

//atcoder/all ver
#include <atcoder/all>
using namespace atcoder;

//my
template<class S, class F, S(*op)(S, S), S(*mapping)(F, S, int), F(composition)(F, F)>
struct LazySegTree{
    int n, size, log;
    vector<S> d;
    vector<F> lz;
    S e;
    F id;
    LazySegTree(int n,  S e, F id)
    :n(n),e(e), id(id){
        size = 1;
        log = 0;
        while(size < n) size <<= 1, log++;
        d.assign(2*size,e);
        lz.assign(size,id);
    }
    void set(int p,S x){
        p += size;
        d[p] = x;
    }
    void build(){
        for(int i=size-1;i>=1;i--){
            update(i);
        }
    }

    void update(int k){
        d[k] = op(d[2*k], d[2*k+1]);
    }
    void all_apply(int k,F f,int len){
        d[k] = mapping(f,d[k],len);
        if(k < size) lz[k] = composition(f,lz[k]);
    }
    void push(int k,int len){
        all_apply(2*k,lz[k],len>>1);
        all_apply(2*k+1,lz[k],len>>1);
        lz[k] = id;
    }
    void apply(int l,int r,F f){
        apply(l,r,f,1,0,size);
    }
    void apply(int l,int r,F f,int k,int a,int b){
        if(r<=a || b<=l) return;
        if(l<=a && b<=r){
            all_apply(k,f,b-a);
            return;
        }
        push(k,b-a);
        int mid=(a+b)/2;
        apply(l,r,f,2*k,a,mid);
        apply(l,r,f,2*k+1,mid,b);
        update(k);
    }

    S prod(int l,int r){
        return prod(l,r,1,0,size);
    }
    S prod(int l,int r,int k,int a,int b){
        if(r<=a || b<=l) return e;
        if(l<=a && b<=r) return d[k];
        push(k,b-a);
        int mid=(a+b)/2;
        return op(
            prod(l,r,2*k,a,mid),
            prod(l,r,2*k+1,mid,b)
        );
    }
    S all_prod(){
        return d[1];
    }
    S get(int p){
        p += size;
        for(int i=log;i>=1;i--){
            push(p>>i,1<<(i));
        }
        return d[p];
    }
};


/*  
lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v);
S : data,  F : lazy 
S op(S a, S b) : S op(S a, S b){return min(a, b)}  とか
S mapping(F f, S x, int) :  親のlazyから子のdataに反映させる関数
F composition(F f, F g) : lazy -> lazy
S e() : op の単位元
F id() : mapping の恒等写像
*/

// //lenが存在するため，区間加算も簡単に実装可能
// struct S{
//     int vl;
//     S():vl(0){} //e
// };
// struct F{
//     int k;
//     F():k(0){} //id
// };
// S op(S a, S b){
//     S res;
//     res.vl = a.vl + b.vl;
//     return res;
// }
// S mapping(F f, S x, int len){
//     S res;
//     res.vl = x.vl + f.k * len;
//     return res;
// }
// F composition(F f ,F g){
//     F res;
//     res.k = f.k + g.k;
//     return res;
// }



// //区間代入・区間和
// using S = int;
// struct F{
//     int val;
//     bool fg;
// };
// S op(S a, S b) {return a + b;}
// S mapping (F f, S x, int len){
//     if(f.fg) return f.val * len;
//     return x;
// }
// F compose(F f, F g){
//     if(f.fg) return f;
//     return g;
// }
// S e(){return 0;}
// F id(){
//     return {0, false};
// }



int main(){
    
}

//g++ tmp.cpp
//./a.out