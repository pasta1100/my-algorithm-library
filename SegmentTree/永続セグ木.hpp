#include <bits/stdc++.h>
using namespace std;

template<typename S, S(*op)(S, S)>
struct PersistentSegTree{
    struct Node{
        S val;
        Node *l, *r;
        Node(S d, Node*l = nullptr, Node*r = nullptr):val(d), l(l), r(r){}
    };
    int n;
    vector<Node*> roots;
    S e;

    int set(int ver, int p, S x){
        roots.push_back(update(roots[ver], 0, n, p, x));
        return roots.size() - 1;
    }
    //sum, xor, min 更新用
    int add(int ver, int p, S x){
        return set(ver, p, op(prod(ver, p, p+1), x));
    }
    S prod(int ver, int l, int r){
        return query(roots[ver], 0, n, l, r);
    }
    S get(int ver, int i){
        return query(roots[ver], 0, n, i, i + 1);
    }
    PersistentSegTree(int _n, S e, vector<S> a):e(e){
        n = 1;
        while(n < _n) n <<= 1;
        roots.push_back(build(0, n, a));
    }
    private:
    Node* build(int l, int r, const vector<S>& a){
        if(l + 1 == r) return new Node(l<(int)a.size()?a[l]:e);
        int m = (l + r) / 2;
        Node* L = build(l, m, a);
        Node* R = build(m, r, a);
        return new Node(op(L->val, R->val), L, R);
    }
    Node* update(Node* prev, int l, int r, int p, S x){
        if(l + 1 == r) return new Node(x);
        int m = (l + r) / 2;
        if(p < m){
            Node* nl = update(prev->l, l, m, p, x);
            return new Node(op(nl->val, prev->r->val), nl, prev->r);
        }
        else{
            Node* nr = update(prev->r, m, r, p, x);
            return new Node(op(prev->l->val, nr->val), prev->l, nr);
        }
    }
    S query(Node* cur, int l, int r, int a, int b){
        if(r <= a || b <= l) return e;
        if(a <= l && r <= b) return cur->val;
        int m = (l + r) / 2;
        return op(query(cur->l, l, m, a, b), query(cur->r, m, r, a, b));
    }
};

using S = long long;
S op(S a, S b){
    return a + b;
}

int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //ここから

    int n, m, q; cin >> n >> m >> q;
    PersistentSegTree<S, op> seg(m, 0, vector<S>(m));
    int c, x, y, z, l, r;
    vector<int> ver(n);
    for(int i = 0; i < q; ++i){
        cin >> c;
        if(c == 1){
            cin >> x >> y; x--; y--;
            ver[x] = ver[y];
        }
        else if(c == 2){
            cin >> x >> y >> z;
            x--; y--;
            ver[x] = seg.set(ver[x], y, z);
        }else{
            cin >> x >> l >> r; x--; l--;
            cout << seg.prod(ver[x], l, r) << endl;
        }
    }
}
/*
g++ main.cpp -g -O0 -std=c++17
gdb ./a.out

*/