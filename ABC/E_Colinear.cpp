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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e5;
int n,t;

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
using P = Point<ll>;
P p[mxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxc = 6;
using tup = tuple<ll,ll,ll>;

tup slv(P p1, P p2) {
    ll a = p2.y - p1.y;
    ll b = p1.x - p2.x;
    if(a<0) {
        a *=-1;
        b *=-1;
    }
    if(a==0) {
        b = abs(b);
    }
    ll d = gcd(a,b);
    a /= d;
    b /= d;
    ll c = 0;
    c -= (a*p1.x + b*p1.y);
    return {a,b,c};
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>p[i].x >>p[i].y;
    }
    rep(ci,0,mxc) {
        int id = rng()%n;
        map<tup,int> mp;
        rep(i,0,n) {
            if(i==id) continue;
            tup cur = slv(p[i], p[id]);
            mp[cur]++;
        }
        for(auto& [ln, ct]: mp) {
            if(ct+1 > (n/2)) {
                cout <<"Yes\n";
                auto [a,b,c] = ln;
                cout <<a <<" " <<b <<" " <<c <<"\n";
                return;
            }
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    // cout <<gcd(0,-2) <<endl;
    // cout <<gcd(-2, 0) <<endl;
    // cout <<gcd(-1,-7) <<endl;
    while(t--) {
        solve();
    }
}