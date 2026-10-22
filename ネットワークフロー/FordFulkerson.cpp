#include <bits/stdc++.h>
using namespace std;

//FordFulkerson法
#define INF 1e9
#define MAX_V 109
struct edge{int to, cap, rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}
int dfs(int s, int t, int f){
    if (s == t) return f;
    used[s] = true;
    for(auto &[to, cap, rev] : G[s]){
        if(!used[to] && cap > 0) {
            int d = dfs(to, t, min(f, cap));
            if(d > 0){
                cap -= d;
                G[to][rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}
int main(){
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int s, t, c;
        cin >> s >> t >> c;
        add_edge(s, t, c);
    }
    cout << max_flow(0, v - 1) << endl;
}