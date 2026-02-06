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
int n,m;
ll a[mxn],x[mxn],y[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>x[i] >>y[i];
    }
    set<pll> s1;
    map<ll,ll> mm;
    map<ll,int> mp;
    vi idx(m);
    iota(all(idx),0);
    sort(all(idx), [&](int i, int j) -> bool {
        return pll{x[i],y[i]}<pll{x[j],y[j]};
    });
    s1.insert({0,0});
    auto getVal = [&](ll val) -> ll {
        if(mm.count(val)) {
            return mm[val];
        } else {
            auto it = s1.lower_bound({val+1,-1});
            it--;
            auto [ls, sgl] = *it;
            return sgl + (val-ls);
        }
    };
    for(int i=0;i<sz(idx);) {
        int j = i;
        while(j<sz(idx) && x[idx[j]]==x[idx[i]]) {
            j++;
        }
        map<ll,int> ct;
        rep(k,i,j) {
            ll cur = getVal(x[idx[k]]-y[idx[k]]);
            ct[cur]++;
        }
        auto [ls,sgl] = *(--s1.end());
        ll sg = sgl + (x[idx[i]]-ls);
        for(auto [key,val]: ct) {
            if(!mp.count(key) || val>=mp[key]) {
                min_self(sg, key);
            }
        }
        mm[x[idx[i]]] = sg;
        if(sg!= sgl+(x[idx[i]]-ls)) {
            if(!mp.count(sg)) {
                mp[sg] = 2;
            } else {
                mp[sg]++;
            }
        }
        ll sgn = max(sg+1, sgl+(x[idx[i]]-ls));
        s1.insert({x[idx[i]]+1,sgn});
        i = j;
    }
    ll xr = 0;
    rep(i,0,n) {
        xr ^= getVal(a[i]);
    }
    if(xr>0) {
        cout <<"Takahashi\n";
    } else {
        cout <<"Aoki\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}