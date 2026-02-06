#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
#define all(x) (x).begin(), (x).end()

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

using P = Point<ll>;
void solve() {
    cin >>n;
    vector<P> vp(n);
    rep(i,0,n) {
        cin >>vp[i].x >>vp[i].y;
    }
    vector vb(n, vector<bitset<mxn>>(n));
    rep(i,0,n) {
        rep(j,0,n) {
            if(j==i) continue;
            rep(k,0,n) {
                if(k==i || k==j) continue;
                ll cr = vp[i].cross(vp[j],vp[k]);
                if(sgn(cr)>0) {
                    // debug() <<imie(i) imie(j) imie(k);
                    vb[i][j].set(k);
                    // cout <<"tes" <<endl;
                }
            }
        }
    }
    // debug() <<"vbb";
    vector vbb(n, vector<bitset<mxn>>(n));
    rep(i,0,n) {
        rep(j,0,n) {
            if(j==i) continue;
            rep(k,0,n) {
                if(k==i || k==j) continue;
                ll cr = vp[i].cross(vp[j],vp[k]);
                if(sgn(cr)<0) continue;
                int ct = (vb[i][j] & vb[j][k] & vb[k][i]).count();
                if(ct==0) {
                    // debug() <<imie(i) imie(j) imie(k);
                    vbb[i][j].set(k);
                }
            }
        }
    }
    int ans = 0, convex=0;
    rep(i,0,n) {
        rep(j,i+1,n) {
            ans += vbb[i][j].count() *vbb[j][i].count();
            // debug()<< imie(i) imie(j) imie(ans);
            rep(k,0,n) {
                if(!vbb[i][j][k]) continue;
                int ct = (vbb[j][i] & vbb[j][k] & vbb[k][i]).count();
                convex += ct;
            }
        }
    }
    // cout <<ans <<" " <<convex <<"\n";
    ans -= convex/2;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}