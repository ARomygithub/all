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

const int mxn=2e5;
int n,q;
typedef pair<int,pii> ipii;

void solve() {
    cin >>n >>q;
    set<pii> s;
    rep(i,0,n) {
        s.insert({i,i});
    }
    vector<ipii> v(q);
    rep(i,0,q) {
        cin >>v[i].se.fi >>v[i].se.se >>v[i].fi;
        v[i].se.fi--; v[i].se.se--;
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    rep(i,0,q) {
        auto it = s.upper_bound({v[i].se.fi,(int)(1e9)}); it--;
        ans += v[i].fi;
        vector<pii> toEr;
        toEr.push_back(*it);
        while(it!=s.end() && it->se < v[i].se.se) {
            it++;
            if(it!=s.end()) {
                toEr.push_back(*it);
                ans += v[i].fi;
            }
        }
        if(sz(toEr)>1) {
            int l = toEr[0].fi, r = toEr[sz(toEr)-1].se;
            for(auto eri: toEr) {
                s.erase(eri);
            }
            s.insert({l,r});
        }
    }
    if(sz(s)==1) {
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}