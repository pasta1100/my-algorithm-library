#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
//UF
struct UnionFind{
	vector<int> data;
	UnionFind(int n):data(n, -1){}
	int find(int x){
		if(data[x] < 0)	return x;
		return data[x] = find(data[x]);
	}
	bool unite(int a, int b){
		a = find(a);	b = find(b);
		if(a == b)	return false;   //既に同じグループ
		if(data[a] > data[b])	swap(a, b);
		data[a] += data[b];
		data[b] = a;
        return true;    //結合成功
	}
	bool connected(int a, int b){
		return (find(a) == find(b)); 
	}
	int size(int x)	{
		return -data[find(x)];
	}
};


struct edge{
	int s, t;
	ll w;
	edge(int s, int t, int w):s(s),t(t),w(w){}
	bool operator<(const edge& other) const{
		return w < other.w;
	}
};

void add_edge(int s, int t, long long w, vv<pll> &G){
    G[s].push_back({t, w});
    G[t].push_back({s, w});
}
//クラスカル法による最小全域木
//MSTを返却
vv<pll> kruskal(int n, v<edge>& e){
	UnionFind uf(n);
	vv<pll> G(n);
	sort(e.begin(), e.end());
	for(auto &[s, t, w]: e){
		if(uf.connected(s, t) == false){
			add_edge(s, t, w, G);
			uf.unite(s, t);		
		}
	}
	return G;
}

int main(){
	int n, m, r;
	cin >> n >> m >> r;
	UnionFind uf(n + m + 1);
	v<edge> V(r + n + m);
	rep(i, r){
		auto &[w, s, t] = V[i];
		cin >> s >> t >> w; s += n;
	}
	rep(i, n + m){
		V[i + r] = {0, i, n + m};
	}
	auto G = kruskal(n, V);
	
}

//g++ tmp.cpp
//./a.out