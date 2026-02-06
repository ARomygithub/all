#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define all(x) begin(x), end(x)
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

const int mxn=1e2;
int n,m;

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

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> bool onseg(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) < 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

template<class P> bool seg_cross(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
    return sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0;
}

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0;
	rep(i,0,n) {
		P q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		//or: if (segDist(p[i], q, a) <= eps) return !strict;
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

vector<Point<ll>> a(mxn*2);
int ok[mxn*2][mxn*2];
double G[mxn*2][mxn*2], dis[mxn*2][mxn*2];
vector<int> vec[mxn*2];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i].x >>a[i].y;
        a[i].x *=2;
        a[i].y *=2;
    }
    rep(i,0,m) {
        cin >>a[i+n].x >>a[i+n].y;
        a[i+n] =a[i+n] * 2ll;
        rep(j,0,n) {
            if(onSegment(a[j], a[(j+1)%n], a[i+n]) && !(a[i+n] == a[(j+1)%n])) {
                vec[j].push_back(i);
            }
        }
    }
    rep(i,0,n+m) {
        rep(j,0,n+m) {
            G[i][j] = 1e9;
            dis[i][j] = hypot((a[i].x - a[j].x) >> 1, (a[i].y - a[j].y) >>1);
        }
    }
    // rep(i,0,n+m) {
    //     rep(j,0,n+m) {
    //         debug() <<imie(i) <<imie(j) <<imie(dis[i][j]);;
    //     }
    // }    
    rep(i,0,n+m) {
        G[i][i] = 0;
        rep(j,i+1,n+m) {
            ok[i][j] = 1;
            rep(k,0,n) {
				if(seg_cross(a[i], a[j], a[k], a[(k+1)%n]) || onseg(a[i], a[j], a[k])) {
					ok[i][j] = 0;
				}                
            }
            ok[i][j] &= inPolygon(a, Point<ll>((a[i].x + a[j].x) >> 1, (a[i].y + a[j].y) >> 1), false);
            if(ok[i][j]) {
                G[i][j] = G[j][i] = dis[i][j];
            }
            // debug() <<imie(i) <<imie(j) <<imie(ok[i][j]);
        }
    }
    rep(k,0,n+m) {
        rep(i,0,n+m) {
            rep(j,0,n+m) {
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
    // rep(i,0,n+m) {
    //     rep(j,0,n+m) {
    //         debug() <<imie(i) <<imie(j) <<imie(G[i][j]);;
    //     }
    // }

    vector<int> pp;
    rep(i,0,n) {
        sort(vec[i].begin(), vec[i].end(), [&](int x, int y) {return dis[x+n][i] < dis[y+n][i]; });
        for(auto x: vec[i]) {
            pp.push_back(x);
            // cout <<x <<"\n";
        }
    }
    double ans = 0;
    rep(i,0,sz(pp)) {
        ans += G[pp[i]+n][pp[(i+1)%(sz(pp))] + n];
    }
    cout <<fixed <<setprecision(10) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}