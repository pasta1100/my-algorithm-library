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

int mod = 1e9 + 7;

vi z_algorithm(string s){
	vi z(s.size());	z[0] = s.size();
	int pos = 1, len = 0;
	while(pos < s.size()){
		while(pos + len < s.size() && s[pos + len] == s[len])	len++;
		z[pos] = len;

		if(len == 0){pos++;	continue;}

		int i = 1;
		while(i < len && i + z[i] < len){
			z[pos + i] = z[i];
			i++;
		}
		pos += i;
		len -= i;
	}

	return z;
}
