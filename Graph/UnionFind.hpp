#include <bits/stdc++.h>
using namespace std;

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

// 重み付きUnionFind
// diff_weight[x] = weight(x) - weight(parent[x])
// weight(x) = 根からxまでの累積重み
// diff(x, y) = weight(y) - weight(x)
// unite(a, b, w): weight(b) - weight(a) = w となるように結合
struct W_UnionFind{
	vector<int> data;
	vector<long long> diff_weight;
	W_UnionFind(int n):data(n, -1), diff_weight(n, 0){}
	int find(int x){
		if(data[x] < 0)	return x;
		int r = find(data[x]);
		diff_weight[x] += diff_weight[data[x]];
		return data[x] = r;
	}
	long long weight(int x){
		find(x);
		return diff_weight[x];
	}
	int diff(int x, int y){
		//assert(connected(x, y));	//connectedチェック
		return weight(y) - weight(x);
	}
	bool unite(int a, int b, int w){
		w += weight(a); w -= weight(b);
		a = find(a);	b = find(b);
		if(a == b)	return w == 0; 	//整合性チェック
		if(data[a] > data[b])	swap(a, b), w = -w;
		data[a] += data[b];
		data[b] = a;
		diff_weight[b] = w;
		return true;
	}
	bool connected(int a, int b){
		return (find(a) == find(b)); 
	}
	int size(int x)	{
		return -data[find(x)];
	}
};
