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

const int mxn=2e5;
ll n,v,t;
ll ti[mxn],a[mxn];

// struct Tree {
//     typedef int T;
//     static constexpr T unit = INT_MIN;
//     T f(T a, T b) { return max(a,b); }
//     vector<T> s; int n;
//     Tree(int n=0, T def = unit) : s(2*n, def), n(n) {}
//     void update(int pos, T val) {
//         for(s[pos += n] = val; pos /= 2;) {
//             s[pos] = f(s[pos*2], s[pos*2+1]);
//         }
//     }
//     T query(int b, int e) {
//         T ra = unit, rb = unit;
//         for(b+=n, e+=n; b < e; b/=2, e/=2) {
//             if(b%2) ra = f(ra, s[b++]);
//             if(e%2) rb = f(s[--e], rb);
//         }
//         return f(ra,rb);
//     }
// };

// auto compress_coords(auto &coords) {
//     vector<pll> original;
//     original.reserve(sz(coords));
//     // ranges::sort(coords);
//     sort(all(coords), [&](auto& ei, auto& ej) -> bool {
//         return ei.get() < ej.get();
//     });
//     int idx = -1;
//     pll prev = {-1e12,-1e12};
//     for(auto& x: coords) {
//         if(x.get()!=prev) {
//             idx++;
//             prev = x;
//             original.push_back(x);
//         }
//         x.get() = {idx,0};
//     }
//     return original;
// }

auto compress_coords0(auto &coords) {
    vector<ll> original;
    original.reserve(sz(coords));
    ranges::sort(coords);
    // sort(all(coords), [&](auto& ei, auto& ej) -> bool {
    //     return ei.get() < ej.get();
    // });
    int idx = -1;
    ll prev = -2e18;
    for(auto& x: coords) {
        if(x.get()!=prev) {
            idx++;
            prev = x;
            original.push_back(x);
        }
        x.get() = idx;
    }
    return original;
}

struct FT {
    vi s;
    FT(int n): s(n,INT_MIN) {}
    void update(int pos, int dif) {
        for(; pos < sz(s); pos |= pos+1) max_self(s[pos],dif);
    }
    int query(int pos) {
        int res = INT_MIN;
        for(; pos > 0; pos &= pos-1) max_self(res, s[pos-1]);
        return res;
    }
};

struct FT2 {
    vector<vector<ll>> ys; vector<FT> ft;
    FT2(int limx): ys(limx) {}
    void fakeUpdate(int x, ll y) {
        for(; x < sz(ys); x |= x+1) ys[x].push_back(y);
    }
    void init() {
        for(auto& v: ys) sort(all(v)), ft.emplace_back(sz(v));
    }
    int ind(int x, ll y) {
        return (int)(lower_bound(all(ys[x]), y) - ys[x].begin());
    }
    void update(int x, ll y, int dif) {
        for(; x < sz(ys); x |= x+1) {
            ft[x].update(ind(x,y),dif);
        }
    }
    int query(int x, ll y) {
        int res = INT_MIN;
        for(; x; x &= x-1) {
            max_self(res, ft[x-1].query(ind(x-1,y)));
        }
        return res;
    }
};
using pil = pair<int,ll>;

void solve() {
    cin >>n >>v;
    rep(i,0,n) {
        cin >>ti[i];
    }
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pll> v1(n+1);
    vector<reference_wrapper<ll>> c;
    v1[0] = {0,0};
    c.push_back(ref(v1[0].fi));
    rep(i,0,n) {
        v1[i+1] = {-(a[i] - ti[i]*v), a[i]+ti[i]*v};
        c.push_back(ref(v1[i+1].fi));
    }
    auto val = compress_coords0(c);
    // auto val1 = compress_coords(c1);
    // auto val2 = compress_coords(c2);
    // rep(i,0,n+1) {
    //     cout <<v1[i].fi <<" " <<val1[i].fi <<"\n";
    // }
    // rep(i,0,n+1) {
    //     cout <<v2[i].fi <<" " <<val2[i].fi <<"\n";
    // }
    FT2 ft2(n+1);
    rep(i,0,n+1) {
        ft2.fakeUpdate(v1[i].fi, v1[i].se);
    }
    ft2.init();
    vi dp(n+1,0);
    dp[0] = 0;
    ft2.update(v1[0].fi,0,0);
    // cout <<v1[0].fi <<endl;
    rep(i,1,n+1) {
        int qry = INT_MIN;
        // cout <<v1[i].fi <<endl;
        max_self(qry, ft2.query(v1[i].fi+1,v1[i].se+1));
        qry++;
        dp[i] = qry;
        ft2.update(v1[i].fi, v1[i].se, dp[i]);
    }
    int mx = 0;
    rep(i,0,n+1) {
        max_self(mx, dp[i]);
    }
    cout <<mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}