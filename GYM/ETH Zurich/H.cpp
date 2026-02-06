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

const int mxn=3e5;
int n,m,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i]; a[i]--;
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    vector v(m, vector<int>());
    rep(i,0,n) {
        v[a[i]].push_back(b[i]);
    }
    int l = 1, r = n/m;
    rep(i,0,m) {
        min_self(r, sz(v[i]));
        sort(v[i].begin(),v[i].end());
    }
    int ans = 0;
    set<pii> s;
    s.insert({0,2e9});
    rep(now,l,r+1) {
        bool ok = 1;
        rep(i,0,m) {
            int j = sz(v[i])-now;
            auto it = s.upper_bound({v[i][j],2e9});
            if(it==s.begin()) {
                ok = 0;
                break;
            }
            it--;
            auto [le, ri] = *it;
            s.erase(it);
            int cur = min(v[i][j],ri);
            if(le<cur) {
                s.insert({le,cur-1});
            }
            if(ri>cur) {
                s.insert({cur+1,ri});
            }
        }
        if(ok) {
            ans = now;
        } else {
            break;
        }
    }
    cout <<ans <<"\n";
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