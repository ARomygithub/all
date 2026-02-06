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

const int mxn=1e5;
int m,n;

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
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts))) {
        for (P p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) < 0) t--;
            // debug() <<imie(t) imie(p.x) imie(p.y);
            if(t>=sz(h)) {
                h.push_back(p);
            } else {
                h[t++] = p;
            }
        }
        // debug() <<"tes\n";
    }
    // debug() <<imie(t);
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

void solve() {
    cin >>m >>n;
    vector<pii> vm(m);
    rep(i,0,m) {
        cin >>vm[i].fi >>vm[i].se;
    }
    vector<P> vp(n);
    map<pii,int> mp;
    rep(i,0,n) {
        cin >>vp[i].x >>vp[i].y;
        mp[{vp[i].x,vp[i].y}] = i;
    }
    vector<int> ans(n,0);
    // if(n<=500) {
    //     rep(i,0,m) {
    //         ll mx = 0;
    //         rep(j,0,n) {
    //             max_self(mx, 1ll*vp[j].x*vm[i].fi + 1ll*vp[j].y*vm[i].se);
    //         }
    //         rep(j,0,n) {
    //             if(mx== 1ll*vp[j].x*vm[i].fi + 1ll*vp[j].y*vm[i].se) {
    //                 ans[j]++;
    //             }
    //         }
    //     }
    //     rep(i,0,sz(ans)) {
    //         cout <<ans[i] <<"\n";
    //     }
    //     return;
    // }
    // assert(false);
    auto hull = convexHull(vp);
    // debug() <<"hey";
    if(sz(hull)>n) {
        hull.resize(n);
    }
    // hull.push_back(hull[0]);
    sort(vm.begin(),vm.end(), [&](pii a, pii b) -> bool {
        if(1ll*a.fi*b.se!=1ll*b.fi*a.se) {
            return (1ll*a.fi*b.se)>(1ll*b.fi*a.se);
        }
        return a.fi<b.fi;
    });
    int l=0,r=0;
    // rep(i,0,sz(hull)) {
    //     debug() <<imie(i)  imie(hull[i].x) imie(hull[i].y);
    // }
    for(int i=0;i<sz(vm);) {
        int j = i;
        auto [a,b] = vm[i];
        while(j<sz(vm) && 1ll*vm[i].fi*vm[j].se==1ll*vm[j].fi*vm[i].se) {
            j++;
        }
        int rp = (r+1)%(sz(hull));
        while(rp!=r && 1ll*hull[rp].x*a+1ll*hull[rp].y*b > 1ll*hull[r].x*a+1ll*hull[r].y*b) {
            r = rp;
            l = rp;
            rp = (r+1)%sz(hull);
        }
        l = r;
        while(rp!=l && 1ll*hull[rp].x*a+1ll*hull[rp].y*b == 1ll*hull[r].x*a+1ll*hull[r].y*b) {
            r = rp;
            rp = (r+1)%sz(hull);
        }
        // while(1ll*hull[l].x*a+1ll*hull[l].y*b != 1ll*hull[r].x*a+1ll*hull[r].y*b) {
        //     l++;
        // }
        // debug() <<imie(l) imie(r) imie(i) imie(j);
        if(l<=r) {
            rep(k,l,r+1) {
                ans[mp[{hull[k].x,hull[k].y}]] += j-i;
            }
        } else {
            rep(k,l,sz(hull)) {
                ans[mp[{hull[k].x,hull[k].y}]] += j-i;
            }
            rep(k,0,r+1) {
                ans[mp[{hull[k].x,hull[k].y}]] += j-i;
            }
        }
        i = j;
    }
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}