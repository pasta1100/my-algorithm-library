#include <iostream>
using namespace std;
using ll = long long;
using ld = long double;

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