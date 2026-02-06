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
typedef pair<pll,pll> plll;

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

const int mxn=300;
int n;
Point<ll> a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i].x >>a[i].y;
    }
    map<plll, set<int>> mp;
    int mx = 0;
    rep(i,0,n) {
        rep(j,i+1,n) {
            plll cur;
            cur.fi = {a[j].y-a[i].y, a[j].x-a[i].x};
            if(cur.fi.se<0) {
                cur.fi.fi *=-1;
                cur.fi.se *=-1;
            } else if(cur.fi.se==0) {
                cur.fi.fi = a[j].x;
            }
            ll d = __gcd(abs(cur.fi.fi),abs(cur.fi.se));
            if(d!=0) {
                cur.fi.fi /=d;
                cur.fi.se /=d;
            }
            cur.se = {a[i].y*a[j].x - a[j].y-a[i].x, a[j].x-a[i].x};
            if(cur.se.se<0) {
                cur.se.fi *=-1;
                cur.se.se *=-1;
            } else if(cur.se.se==0) {
                cur.se.fi = a[j].x;
            }
            d = __gcd(abs(cur.se.fi),abs(cur.se.se));
            if(d!=0) {
                cur.se.fi /=d;
                cur.se.se /=d;
            }
            if(mp.count(cur)) continue;
            mp[cur].insert(i);
            mp[cur].insert(j);
            rep(k,j+1,n) {
                if(a[i].cross(a[j],a[k])==0ll) {
                    mp[cur].insert(k);
                }
            }
            max_self(mx, sz(mp[cur]));
        }
    }
    ll ans = 0;
    int u2 = n-mx;
    if(mx>=u2*2) {
        ans = u2;
    } else {
        ans = (n)/3;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}