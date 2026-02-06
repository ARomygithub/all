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

// CHT
const int mxn=1e5,mxp=1e2;
int n,m,p;
ll d[mxn];

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

void solve() {
    cin >>n >>m >>p;
    rep(i,1,n) {
        cin >>d[i];
    }
    rep(i,1,n) {
        d[i] += d[i-1];
    }
    vector<ll> vdt;
    rep(i,0,m) {
        int h,t; cin >>h >>t; h--;
        vdt.push_back(t-d[h]);
    }
    sort(all(vdt));
    // debug() <<imie(vdt);
    vector<ll> pr(m+1,0);
    rep(i,1,m+1) {
        pr[i] = pr[i-1]+vdt[i-1];
    }
    // debug() <<imie(pr);
    vector vlc(p+1, LineContainer());
    vector dp(p+1, vector<ll>(m+1,1e18));
    dp[0][0] = 0;
    vlc[0].add(0,-(dp[0][0]+pr[0]));
    rep(j,0,m+1) {
        rep(i,1,p+1) {
            if(j==0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = -vlc[i-1].query(vdt[j-1]);
                dp[i][j] += vdt[j-1]*j - pr[j];
            }
            // debug() <<imie(j) imie(i);
            // debug() <<imie(dp[i][j]);
            vlc[i].add(j,-(dp[i][j]+pr[j]));
        }
    }
    cout <<dp[p][m] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
