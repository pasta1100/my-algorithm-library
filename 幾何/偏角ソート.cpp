#include <bits/stdc++.h>
using namespace std;

long long cross(const pair<int,int> &a, const pair<int,int> &b){
    return (long long)a.first * b.second - (long long)a.second * b.first; 
}
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    //外積なので，上と下で分ける
    int ah = (a.second < 0 || (a.second == 0 && a.first < 0));
    int bh = (b.second < 0 || (b.second == 0 && b.first < 0));
    if(ah != bh) return ah < bh;
    long long c = cross(a, b);
    if(c != 0) return c > 0;
    //同じ角度のとき距離が近いほうを返す
    long long ad = (long long)a.first * a.first + (long long)a.second * a.second;
    long long bd = (long long)b.first * b.first + (long long)b.second * b.second;
    return  ad < bd;
}