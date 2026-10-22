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
#define No cout<<"No"<<endl

int modd = 1e9 + 7;

int mxsiz = 1e5, na = -1;	//	not/assigned

int num = 1;
vi L(mxsiz, na), root(mxsiz, na), le(mxsiz, na), ri(mxsiz, na);

int find(int key, int pos){
	if(L[pos] > key && le[pos] != na)	return find(key, le[pos]);
	if(L[pos] < key && ri[pos] != na)	return find(key, ri[pos]);
	if(L[pos] == key)	return pos;
	return -1 * pos;	//not find
}
void insert(int x){
	int par = -1 * find(x, 0), cil = num;
	if(par < 0)	return;	//	既に存在
	
	if(L[par] > x) le[par] = cil;
	if(L[par] < x) ri[par] = cil;
	L[cil] = x;	root[cil] = par;	num++;
}
void pop(int x){
	int pos = find(x, 0), nxt;
	if(pos < 0 || x == na)	return;

	if(le[pos] != na){	//"左の子"が存在
		nxt = le[pos];
		while(ri[nxt] != na)	nxt = ri[nxt];

		if(le[pos] == nxt) le[pos] = na;	//"左の子"の"右の子"が存在しないとき	
		else ri[root[nxt]] = na;
	}
	else if(ri[pos] != na){	//"右の子"が存在
		nxt = ri[pos];
		while(le[nxt] != na)	nxt = le[nxt];
		if(ri[pos] == nxt) ri[pos] = na;	//"右の子"の"左の子"が存在しないとき	
		le[root[nxt]] = na;
	}
	else {//子が存在しない
		if(ri[root[pos]] == pos) ri[root[pos]] = na;
		else le[root[pos]] = na;
		return;
	}
	L[pos] = L[nxt];
}
int main(){
	int Q, s, x;
	cin >> Q;
	/*
		1 x : insert x
		2 x : is exsist x
		3 x : pop x
	*/
	while(Q--){
		cin >> s >> x;
		if(s == 1){
			insert(x);
		}
		else if(s == 2){
			if(find(x, 0) >= 0)	Yes;
			else No;
		}
		else{
			pop(x);
		}
	}
}

//g++ tmp.cpp
//./a.out