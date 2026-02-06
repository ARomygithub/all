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

const int mxn=3e5;
int n,x1,x2;
int c[mxn];

void solve() {
    cin >>n >>x1 >>x2;
    rep(i,0,n) {
        cin >>c[i];
    }
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({c[i],i});
    }
    sort(all(v));
    int l=-1,r=-1;
    auto isgood = [&]() -> bool {
        l = -1, r=-1;
        int idx = n-1;
        ll ct=0, mn=0;
        while(idx>=0 && ct*mn < x1) {
            ct++;
            mn = v[idx].fi;
            idx--;
        }
        if(ct*mn<x1) return 0;
        r = idx+1;
        ct = 0, mn = 0;
        while(idx>=0 && ct*mn < x2) {
            ct++;
            mn = v[idx].fi;
            idx--;
        }
        l = idx+1;
        return ct*mn>=x2;
    };
    auto ans = [&](bool f) -> void {
        cout <<"Yes\n";
        vi v1, v2;
        rep(i,r,n) {
            v1.push_back(v[i].se);
        }
        rep(i,l,r) {
            v2.push_back(v[i].se);
        }
        if(f) {
            v1.swap(v2);
        }
        cout <<sz(v1) <<" " <<sz(v2) <<"\n";
        rep(i,0,sz(v1)) {
            cout <<v1[i]+1 <<" \n"[i==sz(v1)-1];
        }
        rep(i,0,sz(v2)) {
            cout <<v2[i]+1 <<" \n"[i==sz(v2)-1];
        }
    };
    if(isgood()) {
        ans(0);
        return;
    }
    swap(x1,x2);
    if(isgood()) {
        ans(1);
        return;
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}