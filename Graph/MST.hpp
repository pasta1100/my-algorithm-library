#include <bits/stdc++.h>
using namespace std;

//クラスカル法
struct UnionFind{
    vector<int> data;
    UnionFind(int n):data(n, -1){}
    int find(int x){
        if(data[x] < 0) return x;
        return data[x] = find(data[x]);
    }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return false;
        if(data[a] > data[b]) swap(a, b);
        data[a] += data[b];
        data[b] = a;
        return true;
    }
    bool connected(int a, int b){
        return find(a) == find(b);
    }
    int size(int x){
        return -data[find(x)];
    }
};

struct edge{
    int s, t;
    long long w;
    edge(int s = 0, int t = 0, long long w = 4e18):s(s),t(t),w(w){}
    bool operator<(const edge& o) const{
        return w < o.w;
    }
};

//MSTの辺和を返す
long long mst(int n, vector<edge> e){
    if(n <= 1) return 0;	//頂点が1以下ならば辺は0

    long long res = 0;
    int en = 0;
    sort(e.begin(), e.end());
    UnionFind uf(n);
    for(auto &i: e){
        if(uf.unite(i.s, i.t) == true){
            res += i.w;
            en++;
        }
    }
    if(en != n - 1) return 4e18;	//存在しない
    return res;
}


//g++ tmp.cpp
//./a.out