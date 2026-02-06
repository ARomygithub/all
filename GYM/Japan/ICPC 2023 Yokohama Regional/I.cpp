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

const int mxn=500;
int n,m;

void doCumulative(vector<Point<ll>>& v) {
    int szi = sz(v);
    sort(v.begin(), v.end(), [&](Point<ll> a, Point<ll> b) {
        return 1ll*a.y*b.x < 1ll*b.y*a.x;
    });
    rep(i,1,szi) {
        v[i].x += v[i-1].x;
        v[i].y += v[i-1].y;
    }
}

void solve() {
    cin >>n >>m;
    vector<Point<ll>> vn(n), vm(m);
    rep(i,0,n) {
        cin >>vn[i].x;
    }
    rep(i,0,n) {
        cin >>vn[i].y;
    }
    rep(i,0,m) {
        cin >>vm[i].x;
    }
    rep(i,0,m) {
        cin >>vm[i].y;
    }
    doCumulative(vn);
    doCumulative(vm);
    rep(j,0,m) {
        rep(i,0,n) {
            Point<ll> u = (i>0?vn[i-1]: Point<ll>());
            if(sgn(u.cross(vn[i],vm[j])) < 0) {
                cout <<"No\n";
                return;
            }
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}