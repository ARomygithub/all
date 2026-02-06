#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second
#define debug(x) cout <<#x <<": " <<x <<endl;

template<class T> int sgn(T x) { return (x>0) - (x<0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    double dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y,x); }
    P rotate(double a) const {
        return P(x*cos(a) - y*sin(a), x*sin(a)+y*cos(a));
    }
};
using P = Point<double>;
const int mxn = 12;
int n;
P a[mxn];

template<typename T>
void min_self(T& x, T y) {
    x = min(x,y);
}

double slv(vector<P>& v) {
    vector dp(n, vector<double>(1<<n,1e9));
    rep(i,0,n) {
        dp[i][1<<i] = 0;
    }
    rep(bit,1,(1<<n)) {
        if(__builtin_popcount(bit)<=1) continue;
        rep(j,0,n) {
            rep(k,0,n) {
                if(j==k) continue;
                if(((bit>>j)&1) && ((bit>>k)&1)) {
                    // debug(dp[k][bit]);
                    // debug(dp[j][bit^(1<<k)]);
                    // debug(v[j].x);
                    // debug(v[j].y);
                    // debug(v[k].x);
                    // debug(v[k].y);
                    min_self(dp[k][bit], dp[j][bit^(1<<k)] + abs(v[j].x-v[k].x) + abs(v[j].y - v[k].y));
                    // debug(bit);
                    // debug(j);
                    // debug(k);
                }
            }
        }
    }
    double ret = 1e9;
    rep(i,0,n) {
        min_self(ret, dp[i][(1<<n)-1]);
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i].x >>a[i].y;
    }
    // cout <<fixed <<setprecision(8);
    double ans = 1e9;
    rep(i,0,n) {
        rep(j,i+1,n) {
            double ang = (a[j]-a[i]).angle();
            vector<P> v;
            rep(k,0,n) {
                v.push_back(a[k].rotate(-ang));
            }
            ans = min(ans, slv(v));
        }
    }
    cout <<fixed <<setprecision(8) <<ans <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}