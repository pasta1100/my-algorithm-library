#include <bits/stdc++.h>
using namespace std;
struct SCC {
    int n;
    vector<vector<int>> g, scc;
    vector<int> ord, low, comp;	//comp: scc番号
    vector<bool> in_st;
    stack<int> st;
    int timer, comp_cnt;

    SCC(int n) : n(n), g(n), ord(n, -1), low(n), comp(n, -1), in_st(n, false), timer(0), comp_cnt(0) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    void dfs(int v) {
        ord[v] = low[v] = timer++;
        st.push(v);
        in_st[v] = true;
        for (int to : g[v]) {
            if (ord[to] == -1) {
                dfs(to);
                low[v] = min(low[v], low[to]);
            } else if (in_st[to]) {
                low[v] = min(low[v], ord[to]);
            }
        }
        // SCCの根
        if (ord[v] == low[v]) {
            while (true) {
                int u = st.top(); st.pop();
                in_st[u] = false;
                comp[u] = comp_cnt;
                if (u == v) break;
            }
            comp_cnt++;
        }
    }

    // 実行
    vector<vector<int>> build() {
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) dfs(i);
        }
		//SCCグループ作成
		//逆トポソなのでreverse(all(scc))で直すこと想定
		scc.resize(comp_cnt);
		for(int i = 0; i < n; i++){
			scc[comp[i]].push_back(i);
		}
        return scc;
    }
};

int main(){
	int n, m;
	cin >> n >> m;

	SCC g(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g.add_edge(u, v);
	}

	auto scc = g.build(); // SCCのグラフ
}
/*

g++ main.cpp -O2 -std=c++17
./a.out

*/