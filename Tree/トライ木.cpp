#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define el '\n'
#define Yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl

int modd = 1e9 + 7;

int num = 1;
struct Node{
	map<int, Node*> to;	//val, next pointer
	vi data;
	auto unite(int val){
		if(!to[val]){
			to[val] = new Node();
		}
		return to[val];
	}
};

v<pii> A;
v<Node*> P;

void solve(Node* D){
	for(auto i : D->data)	cout << i << " ";
	for(auto [key, val]: D->to){
		solve(val);
	}
}
/*https://atcoder.jp/contests/abc437/editorial/14880*/
int main(){
	int n;	cin >> n;
	A.resize(n + 1);
	P.resize(n + 1);	P[0] = new Node();
	rep(i, n){
		auto &[x, y] = A[i + 1];
		cin >> x >> y;
		P[i + 1] = P[x]->unite(y);
		P[i + 1]->data.push_back(i + 1);
	}

	solve(P[0]);
	cout << el;
}

//g++ tmp.cpp
//./a.out