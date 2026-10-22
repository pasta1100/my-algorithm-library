/*テンプレ地帯*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const double EPS = 1e-9;
int sgn(ld x){  //EPSより小さいとき0と評価
    if(x > EPS) return 1;
    if(x < -EPS) return -1;
    return 0;
}
struct Pt{
    ld x, y;
    Pt(ld x = 0, ld y = 0):x(x),y(y){}

    Pt operator+ (const Pt& p)const{return Pt(x + p.x, y + p.y);}
    Pt operator- (const Pt& p)const{return Pt(x - p.x, y - p.y);}
    Pt operator* (long double k)const{return Pt(x * k, y * k);}
    friend Pt operator* (long double k, const Pt& p){return p * k;}
    Pt operator/ (long double k)const{return Pt(x / k, y / k);}
    Pt& operator+= (const Pt& p){x += p.x; y += p.y; return *this;}
    Pt& operator-= (const Pt& p){x -= p.x; y -= p.y; return *this;}
};
ld abs(Pt a){    //dist
    return sqrt(a.x * a.x + a.y * a.y);
}
ld dot(Pt a, Pt b){  //内積
    return a.x * b.x + a.y * b.y;
}
ld det(Pt a, Pt b){  //外積
    return a.x * b.y - a.y * b.x;
}
ld cross(Pt a, Pt b, Pt c){ //a-b, a-cの外積
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
Pt projection(Pt A, Pt B, Pt P){    //点Pの直線ABへの射影
    Pt AB = B - A;
    if(sgn(dot(AB, AB)) == 0) return A; //ABは点なので射影もAとなる
    Pt AP = P - A;
    ld t = dot(AB, AP) / dot(AB, AB);
    return Pt(A.x + AB.x * t, A.y + AB.y * t);
}
bool intersect(Pt a, Pt b, Pt c, Pt d){ //交差判定
    int s1 = sgn(cross(a, b, c));
    int s2 = sgn(cross(a, b, d));
    int s3 = sgn(cross(c, d, a));
    int s4 = sgn(cross(c, d, b));
    // 一般交差（X型）
    if(s1 * s2 < 0 && s3 * s4 < 0) return true;
    auto in = [&](ld a, ld b, ld c){
        if(a > b) swap(a, b);
        return a <= c + EPS && c <= b + EPS;
    };

    // 端点・共線（含む）
    if(s1 == 0 && in(a.x, b.x, c.x) && in(a.y, b.y, c.y)) return true;
    if(s2 == 0 && in(a.x, b.x, d.x) && in(a.y, b.y, d.y)) return true;
    if(s3 == 0 && in(c.x, d.x, a.x) && in(c.y, d.y, a.y)) return true;
    if(s4 == 0 && in(c.x, d.x, b.x) && in(c.y, d.y, b.y)) return true;

    return false;
}
bool on_seg(Pt a, Pt b, Pt p){  //線分上かどうか
    return sgn(cross(a, b, p)) == 0 &&
           sgn(dot(p - a, p - b)) <= 0;
}
/*ここまで*/


/* 応用例 */

//点の進行方向
int iSP(Pt a, Pt b, Pt c){
    Pt ab = b - a;
    Pt ac = c - a;
    int d = sgn(det(ab, ac));
    if(d > 0) return 1; //a→b→c が左折　counter-clockwise
    if(d < 0) return -1;//a→b→c が右折  clockwise

    if(sgn(dot(ab, ac)) < 0) return -2;  // c-a-b
    if(dot(ab, ab) < dot(ac, ac)) return 2;    // a-b-c
    return 0;   //otherwise (a-c-b)
}
//偏角ソート
auto op = [](Pt a, Pt b){
    auto half = [](Pt p){   //半球面より上かどうか
        return (p.y > 0 || (p.y == 0 && p.x > 0));
    };

    if(half(a) != half(b)) return half(a) > half(b);
    return det(a, b) > 0;
};
//y→x sort
inline bool operator<(const Pt& a, const Pt& b){
    if(sgn(a.x - b.x)) return sgn(a.x - b.x) < 0;
    return sgn(a.y - b.y) < 0; 
}

//偏角
ld pt_arg(Pt a){return atan2(a.y, a.x);}   

//点Pの直線ABへの反射
Pt reflection(Pt A, Pt B, Pt P){    
    Pt M = projection(A, B, P);
    Pt PM = M - P;
    return M + PM;
}

bool is_parallel(Pt a, Pt b){ //平行
    return sgn(det(a, b)) == 0;
}
bool is_orthogonal(Pt a, Pt b){ //垂直
    return sgn(dot(a, b)) == 0;
}

//交点(共線は考慮しない)
//求め方 https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f
Pt intersection(Pt a, Pt b, Pt c, Pt d){
    ld s1 = cross(c, d, a), s2 = cross(c, d, b);
    if(sgn(s1) == sgn(s2)) return Pt(); //not interact
    //端点含む
    return a + (b - a) * s1 / (s1 - s2);
}

//線分距離
ld seg_dist(Pt a, Pt b, Pt c, Pt d){
    if(intersect(a,b,c,d)) return 0;

    auto f = [&](Pt p, Pt a, Pt b){
        Pt h = projection(a, b, p);
        if(on_seg(a, b, h)) return abs(p - h);
        return min(abs(p - a), abs(p - b));
    };

    return min({
        f(a, c, d),
        f(b, c, d),
        f(c, a, b),
        f(d, a, b)
    });
}


//多角形面積
ld polygon_area(const vector<Pt>& p){
    int n = p.size();
    ld s = 0;
    for(int i = 0; i < n; ++n){
        s += det(p[i], p[(i+1)%n]);
    }
    return abs(s) / 2;  //反時計回りは正,時計回りは負
}