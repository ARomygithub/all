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
int n,m,t;
int a[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({a[i],i});
    }
    sort(all(v));
    if(m==0) {
        vector<pii> ans;
        int len = 0;
        rep(i,0,n-2) {
            int idn = v[n-1].se;
            if(a[idn]<= v[n-2].fi) {
                break;
            }
            a[idn] -= v[i].fi;
            ans.push_back({v[i].se, idn});
            len = i+1;
        }
        int idn = v[n-1].se;
        if(a[idn] > v[n-2].fi) {
            cout <<"-1\n";
            return;
        }
        rep(i,len,n-2) {
            ans.push_back({v[i].se, v[i+1].se});
        }
        ans.push_back({idn, v[n-2].se});
        cout <<sz(ans) <<"\n";
        rep(i,0,sz(ans)) {
            cout <<ans[i].fi+1 <<" " <<ans[i].se+1 <<"\n";
        }
    } else {
        if(m*2>n) {
            cout <<"-1\n";
            return;
        }
        vector<pii> ans;
        rep(i,0,n-m*2) {
            ans.push_back({v[i].se, v[i+1].se});
        }
        rep(i,n-m, n) {
            ans.push_back({v[i].se, v[i-m].se});
        }
        cout <<sz(ans) <<"\n";
        rep(i,0,sz(ans)) {
            cout <<ans[i].fi+1 <<" " <<ans[i].se+1 <<"\n";
        }
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