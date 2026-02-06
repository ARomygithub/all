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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5,mxa=1e5;
int n;
typedef pair<int,pii> ipii;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

void solve() {
    cin >>n;
    vector<ipii> v,h;
    rep(i,0,n) {
        int x1,y1,x2,y2; cin >>x1 >>y1 >>x2 >>y2;
        if(x1==x2) {
            v.push_back({x1,{y1,y2}});
        } else {
            h.push_back({y1,{x1,1}});
            h.push_back({y1,{x2+1,-1}});
        }
    }
    sort(v.begin(),v.end());
    sort(h.begin(),h.end(), [&](ipii a, ipii b) -> bool {
        return a.se<b.se;
    });
    ll ans = 0;
    int idh = 0,idv=0;
    FT ft(mxa+1);
    for(int x=1;x<=mxa;x++) {
        while(idh<sz(h) && h[idh].se.fi==x) {
            ft.update(h[idh].fi, h[idh].se.se);
            idh++;
        }
        while(idv<sz(v) && v[idv].fi==x) {
            ans += ft.query(v[idv].se.se+1) - ft.query(v[idv].se.fi); 
            idv++;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}