#include <bits/stdc++.h>
using namespace std;

//入力配列は単調非減少
vector<int> Min_Plus_Convolution(const vector<int>& a, const vector<int>& b){
    vector<int> res(1, a[0] + b[0]);
    int i = 1, j = 1;
    while(i < a.size() && j < b.size()){
        if(a[i] - a[i - 1] < b[j] - b[j - 1]){
            res.push_back(res.back() + a[i] - a[i - 1]);
            ++i;
        }else{
            res.push_back(res.back() + b[j] - b[j - 1]);
            ++j;
        }
    }
    while(i < a.size()){
        res.push_back(res.back() + a[i] - a[i - 1]);
        ++i;
    }
    while(j < b.size()){
        res.push_back(res.back() + b[j] - b[j - 1]);
        ++j;
    }
    return res;
}
