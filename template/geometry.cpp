/*
My competitive programming library
Source:https://github.com/pasta1100/my-algorithm-library
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class S> using v = vector<S>;
template <class S> using vv = vector<vector<S>>;
template <class S> using vvv = vector<vector<vector<S>>>;
#define rep(...) overload_rep(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define overload_rep(_1, _2, _3, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define sp ' '
#define Yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl
template<class T>
bool chmin(T &a, const T &b){
    if (b < a){ a = b; return true; }
    return false;
}
template<class T>
bool chmax(T &a, const T &b){
    if (b > a){ a = b; return true; }
    return false;
}

using mtup = tuple<int, int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const int mod = 998244353;
// const int mod = 1e9 + 7;

const ld EPS = 1e-9;
struct Pt{
    ld x, y;
    Pt(ld x=0, ld y=0):x(x),y(y){}

    Pt operator+(const Pt& p) const { return {x+p.x,y+p.y}; }
    Pt operator-(const Pt& p) const { return {x-p.x,y-p.y}; }
    Pt operator*(ld k) const { return {x*k,y*k}; }
    Pt operator/(ld k) const { return {x/k,y/k}; }

    Pt& operator+=(const Pt& p){ x+=p.x; y+=p.y; return *this; }
};

int sgn(ld x){
    if(x > EPS) return 1;
    if(x < -EPS) return -1;
    return 0;
}

ld dot(Pt a, Pt b){ return a.x*b.x + a.y*b.y; } //内積
ld det(Pt a, Pt b){ return a.x*b.y - a.y*b.x; } //外積
ld cross(Pt a, Pt b, Pt c){ //外積2
    return det(b-a, c-a);
}
Pt projection(Pt a, Pt b, Pt p){ //射影
    Pt ab = b-a;
    ld d = dot(ab, ab);
    if(sgn(d) == 0) return a; // 追加
    ld t = dot(p-a, ab)/d;
    return a + ab*t;
}
bool on_seg(Pt a, Pt b, Pt p){  //線分上か
    return sgn(cross(a,b,p))==0 && sgn(dot(p-a,p-b))<=0;
}
bool intersect(Pt a, Pt b, Pt c, Pt d){ //交差するか
    int s1 = sgn(cross(a,b,c));
    int s2 = sgn(cross(a,b,d));
    int s3 = sgn(cross(c,d,a));
    int s4 = sgn(cross(c,d,b));

    if(s1*s2<0 && s3*s4<0) return true;
    auto in = [&](ld a, ld b, ld c){
        if(a>b) swap(a,b);
        return a<=c+EPS && c<=b+EPS;
    };

    if(s1==0 && in(a.x,b.x,c.x)&&in(a.y,b.y,c.y)) return true;
    if(s2==0 && in(a.x,b.x,d.x)&&in(a.y,b.y,d.y)) return true;
    if(s3==0 && in(c.x,d.x,a.x)&&in(c.y,d.y,a.y)) return true;
    if(s4==0 && in(c.x,d.x,b.x)&&in(c.y,d.y,b.y)) return true;
    return false;
}

int main(){
    //高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    //ここから
}
/*
cppt
cppt_ge
seg, bit, uf

g++ main.cpp -O2 -std=c++17
./a.out

*/