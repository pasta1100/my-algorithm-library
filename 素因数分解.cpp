#include <bits/stdc++.h>
using namespace std;

//線形篩
struct Sieve {
    vector<int> spf; // smallest prime factor
    vector<int> primes;
    int MAXV;

    Sieve(int MAXV) : MAXV(MAXV), spf(MAXV + 1, 0){build();}
    void build() {
        for (int i = 2; i <= MAXV; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (1LL * i * p > MAXV || p > spf[i]) break;
                spf[i * p] = p;
            }
        }
    }
    //素数判定
    bool is_prime(int x) {
        return x >= 2 && spf[x] == x;
    }
    //素因数分解
    vector<pair<int,int>> factorize(int x) {
        vector<pair<int,int>> res;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            res.push_back({p, cnt});
        }
        return res;
    }
    //xの約数列挙
    vector<int> divisors(int x) {
        auto fac = factorize(x);
        vector<int> res = {1};

        for (auto [p, c] : fac) {
            int sz = res.size();
            int mul = 1;
            for (int i = 0; i < c; i++) {
                mul *= p;
                for (int j = 0; j < sz; j++) {
                    res.push_back(res[j] * mul);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
//篩最大サイズ
int MXSIZ = 100000;


int main(){

}