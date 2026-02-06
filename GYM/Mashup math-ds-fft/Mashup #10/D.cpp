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

const int mxn=1e5;
int n,m,k,t;
ll x[mxn];
using pipi = pair<pii,pii>;
using pipii = pair<pipi,int>;

void solve() {
    cin >>n >>m >>k;
    vector<pipii> lad(k);
    map<pii,ll> dp;
    set<pii> sn;
    rep(i,0,n) {
        cin >>x[i];
    }
    rep(i,0,k) {
        int a,b,c,d,h; cin >>a >>b >>c >>d >>h;
        a--,b--,c--,d--;
        lad[i] = {{{a,b},{c,d}},h};
        sn.insert({a,b});
        sn.insert({c,d});
        dp[{a,b}] = 1e18;
        dp[{c,d}] = 1e18;
    }
    sort(all(lad));
    sn.insert({0,0});
    dp[{0,0}] = 0;
    sn.insert({n-1,m-1});
    dp[{n-1,m-1}] = 1e18;
    auto it = sn.begin();
    int eid = 0;
    while(it!=sn.end()) {
        auto it2 = it;
        vector<pii> vcur;
        while(it2!= sn.end() && (it2->fi)==(it->fi)) {
            vcur.push_back(*it2);
            it2++;
        }
        rep(i,1,sz(vcur)) {
            auto [a,b] = vcur[i];
            auto [ap,bp] = vcur[i-1];
            min_self(dp[{a,b}], dp[{ap,bp}] + x[a]*abs(b-bp));
        }
        per(i,sz(vcur)-2,-1) {
            auto [a,b] = vcur[i];
            auto [ap,bp] = vcur[i+1];
            min_self(dp[{a,b}], dp[{ap,bp}] + x[a]*abs(b-bp));
        }
        int a = vcur[0].fi;
        while(eid<k && lad[eid].fi.fi.fi==a) {
            auto [ai,bi] = lad[eid].fi.fi;
            auto [ci,di] = lad[eid].fi.se;
            if(dp[{ai,bi}]!=1e18)  {
                min_self(dp[{ci,di}], dp[{ai,bi}] - lad[eid].se);
            }
            eid++;
        }
        it = it2;
    }
    if(dp[{n-1,m-1}]==1e18) {
        cout <<"NO ESCAPE\n";
    } else {
        cout <<dp[{n-1,m-1}] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}