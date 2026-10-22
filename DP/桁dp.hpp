#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
const int mod = 1e9 + 7;

const int mxsiz = 100;
//上から桁dp
void digitdp(string s, int D){
    int n = s.size();
    int mxd = 9; //0-9, 10進法
    //初期状態:制限あり,leadingzeroあり，状態0
    ll dp[2][2][mxsiz] = {};
    dp[1][1][0] = 1;
    for(int i = 0; i < n; i++){
        ll ndp[2][2][mxsiz] = {};
        int limit = s[i] - '0';
        for(int tight = 0; tight < 2; tight++){
            for(int lz = 0; lz < 2; lz++){
                for(int st = 0; st < D; st++){
                    if(dp[tight][lz][st] == 0) continue;
                    //制限下か？
                    int mx = tight ? limit : mxd;
                    for(int j = 0; j <= mx; j++){
                        int nti = (tight && (j == mx)) ? 1 : 0;
                        int nlz = (lz && (j == 0)) ? 1 : 0;

                        int nst = nlz ? 0 : (st + j) % D;
                        ndp[nti][nlz][nst] += dp[tight][lz][st];
                        ndp[nti][nlz][nst] %= mod;
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    cout << (dp[0][0][0] + dp[1][0][0]) % mod << el;
}