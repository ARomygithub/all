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

const int mxn=5e5;
int n, a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pref(n+1,0);
    rep(i,1,n+1) {
        pref[i] = pref[i-1]+a[i-1];
    }
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({a[i],i});
    }
    sort(all(v));
    vector<ll> ans(n,0);
    vi le(n,n), ri(n,0);
    for(auto [ai,id]: v) {
        int la = id, ra = id+1;
        while(true) {
            ll sm = pref[ra]-pref[la];
            if(la>0 && a[la-1]<sm) {
                la--;
                max_self(ra, ri[la]);
                min_self(la, le[la]);
            } else if(ra<n && a[ra]<sm) {
                ra++; 
                min_self(la, le[ra-1]);
                max_self(ra, ri[ra-1]);
            } else {
                break;
            }
        }
        le[id] = la;
        ri[id] = ra; 
        ans[id] = pref[ra]-pref[la];
    }
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