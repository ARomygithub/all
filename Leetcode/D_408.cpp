#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
    P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
    double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
    if (h2 < 0) return {};
    if (h2 == 0) return {p};
    P h = ab.unit() * sqrt(h2);
    return {p - h, p + h};
}

typedef Point<double> P;
bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {
    if (a == b) { return false; }
    P vec = b - a;
    double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
           p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if (sum*sum < d2 || dif*dif > d2) return false;
    P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
    *out = {mid + per, mid - per};
    return true;
}

double segDist(P& s, P& e, P& p) {
    if (s==e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}
bool onSegment(P& a, P& b, P& p) {
    return segDist(a,b,p) < 1e-10;
}

bool inside(P& cen, double r, P& p) {
    return (p-cen).dist2() <=r*r;
}

struct UF {
    vi e;
    vector<vector<bool>> flag;
    UF(int n) : e(n, -1), flag(n, vector<bool>(4,0)) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        rep(i,0,4) {
            flag[a][i] = flag[a][i] || flag[b][i];
        }
        return true;
    }
};

bool inRec(P p, double x, double y) {
    return p.x>=0.0&&p.x<=x&&p.y>=0&&p.y<=y;
}

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        UF uf(sz(circles));
        rep(i,0,sz(circles)) {
            vector<P> v = {P(0,0),P(X,0),P(X,Y),P(0,Y),P(0,0)};
            P cen(circles[i][0],circles[i][1]);
            double r = circles[i][2];
            rep(j,0,4) {
                auto res = circleLine(cen,r, v[j],v[j+1]);
                if(sz(res)) {
                    if(onSegment(v[j],v[j+1],res[0])) {
                        uf.flag[i][j] = 1;
                        continue;
                    }
                    if(sz(res)>1 && onSegment(v[j],v[j+1],res[1])) {
                        uf.flag[i][j] = 1;
                        continue;
                    }
                }
                if(inside(cen,r, v[j])) {
                    uf.flag[i][j] = 1;
                }
            }
        }
        rep(i,0,sz(circles)) {
            rep(j,i+1,sz(circles)) {
                pair<P, P> out;
                P cen1(circles[i][0],circles[i][1]);
                P cen2 (circles[j][0], circles[j][1]);
                double r1 = circles[i][2], r2 = circles[j][2];
                if(circleInter(cen1, cen2, r1, r2, &out)) {
                    if(inRec(out.fi, X, Y) || inRec(out.se,X,Y)) {
                        uf.join(i,j);
                    } 
                }
            }
        }
        rep(i,0,sz(circles)) {
            int u = uf.find(i);
            if(uf.flag[u][0] && uf.flag[u][2]) return false;
            if(uf.flag[u][1] && uf.flag[u][3]) return false;
            if(uf.flag[u][0] && uf.flag[u][3]) return false;
            if(uf.flag[u][1] && uf.flag[u][2]) return false;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}