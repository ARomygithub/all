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
int n,t;
using plll = pair<pll,ll>;
const ll inf = 2e18;

void solve() {
    cin >>n;
    set<plll> s;
    s.insert({{1ll,inf}, 0ll});
    auto mrg = [&](plll cur) -> void {
        auto it = s.find(cur);
        vector<plll> toer;
        if(it!=s.begin()) {
            auto itp = it; itp--;
            if(itp->se == cur.se) {
                toer.push_back(*itp);
                toer.push_back(cur);
                cur.fi.fi = itp->fi.fi;
            }
        }
        auto itn = it; itn++;
        if(itn!=s.end()) {
            if(itn->se == cur.se) {
                toer.push_back(*itn);
                toer.push_back(cur);
                cur.fi.se = itn->fi.se;
            }
        }
        if(sz(toer)) {
            for(auto& x: toer) {
                s.erase(x);
            }
            s.insert(cur);
        }
    };
    rep(i,0,n) {
        char c; 
        ll l,p;
        cin >>c >>l >>p;
        bool ok = 1;
        if(c=='|') {
            auto it = s.upper_bound({{p,inf},inf});
            it--;
            auto [lr, hi] = *it;
            auto [le,ri] =lr;
            s.erase(it);
            if(le<p) {
                s.insert({{le,p-1},hi});
            }
            s.insert({{p,p},hi+l});
            if(p<ri) {
                s.insert({{p+1,ri},hi});
            }
            mrg({{p,p},hi+l});
        } else {
            auto it = s.upper_bound({{p,inf},inf});
            it--;
            auto [lr, hi] = *it;
            auto [le,ri] =lr;
            if(p+l-1 > ri) {
                ok = 0;
            } else {
                s.erase(it);
                if(le<p) {
                    s.insert({{le,p-1},hi});
                }
                s.insert({{p,p+l-1},hi+1});
                if(p+l<=ri) {
                    s.insert({{p+l,ri},hi});
                }
                mrg({{p,p+l-1},hi+1});
            }  
        }
        if(ok) {
            cout <<"S";
        } else {
            cout <<"U";
        }
    }
    cout <<"\n";
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