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
int n;

void solve() {
    cin >>n;
    vector<pii> pos(n);
    int id = 0,ipos=0;
    vi ans(n,-1);
    rep(i,0,n*2) {
        char qt; cin >>qt;
        if(qt=='+') {
            id++;
        } else {
            int x; cin >>x;
            pos[ipos] = {id,x};
            ipos++;
        }
    }
    set<int> sp;
    set<pii> s;
    rep(i,0,n) {
        sp.insert(i);
    }
    auto slv = [&](vector<pii>& v, int idi) -> void {
        sort(all(v));
        rep(i,0,sz(v)) {
            auto [idy, y] = v[i];
            auto it = sp.lower_bound(idi);
            if(it==sp.end() || (*it)>=idy) {
                cout <<"NO\n";
                exit(0);
            }
            ans[*it] = y;
            sp.erase(it);
        }
    };
    per(i,n-1,-1) {
        auto [idi,x] = pos[i];
        if(sz(s)) {
            vector<pii> v;
            while(sz(s) && (*s.begin()).fi<x) {
                auto [y,idy] = *s.begin();
                s.erase(s.begin());
                v.push_back({idy,y});
            }
            slv(v,idi);
        }
        s.insert({x,idi});
    }
    vector<pii> v;
    while(sz(s)) {
        auto [y, idy] = *s.begin();
        s.erase(s.begin());
        v.push_back({idy,y});
    }
    slv(v,0);
    cout <<"YES\n";
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}