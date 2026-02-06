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
const int mxn=2500;
int n;
Point<ll> arr[mxn];
int loc[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>arr[i].x >>arr[i].y;
    }
    sort(arr,arr+n);
    vector<pii> slo;
    rep(i,0,n) {
        rep(j,i+1,n) {
            slo.push_back({i,j});
        }
    }
    sort(slo.begin(), slo.end(), [](pii a, pii b) {
        Point<ll> p0(0,0);
        ll v = p0.cross(arr[a.se]-arr[a.fi],arr[b.se]-arr[b.fi]);
        if(v) return v>0;
        return a<b;
    });
    ll ans = 0;
    iota(loc,loc+n,0);
    rep(i,0,sz(slo)) {
        pii v = slo[i];
        // cout <<arr[v.fi] <<arr[v.se] <<"\n";
        ll w = n-1-max(loc[v.fi],loc[v.se]);
        ans += w*(w-1)*(w-2)/6;
        w = min(loc[v.fi],loc[v.se]);
        ans += w*(w-1)*(w-2)/6;
        swap(loc[v.fi],loc[v.se]);
    }
    ans = 1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/24 - ans;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}