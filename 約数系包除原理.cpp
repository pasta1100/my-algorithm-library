#include <bits/stdc++.h>
using namespace std;

//関数定義:https://manabitimes.jp/math/1283
//約数系包除原理
//mu  0:平方因子を含む  -1:約数奇数個  1:偶数個 
vector<int> mobius(int n){
    vector<int> mu(n+1,1);
    vector<int> prime;
    vector<bool> isprime(n+1,true);

    for(int i=2;i<=n;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=i;j<=n;j+=i){
                isprime[j]=false;
                mu[j]*=-1;
            }
            long long ii=1LL*i*i;
            for(long long j=ii;j<=n;j+=ii){
                mu[j]=0;
            }
        }
    }
    return mu;
}
