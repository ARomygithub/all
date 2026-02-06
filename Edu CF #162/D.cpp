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
int n,t;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> ri(n);
    vector<ll> pref(n+1);
    rep(i,0,n) {
        pref[i+1] = pref[i]+a[i];
    }
    ri[n-1] = n-1;
    per(i,n-2,-1) {
        if(a[i]==a[i+1]) {
            ri[i] = ri[i+1];
        } else {
            ri[i] = i;
        }
    }
    vector<int> ans(n,-1);
    rep(i,0,n) {
        int ct=1e9;
        int l=0,r=i-1;
        while(l<=r) {
            int mid = (l+r)/2;
            ll s = pref[i]-pref[mid];
            if(s>a[i] && (ri[mid]<i-1 || a[mid]>a[i])) {
                min_self(ct, i-mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        l = i+1,r=n-1;
        while(l<=r) {
            int mid = (l+r)/2;
            ll s= pref[mid+1]- pref[i+1];
            if(s>a[i] && (ri[i+1]<mid || a[i+1]>a[i])) {
                min_self(ct, mid-i);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(ct<1e9) {
            ans[i] = ct;
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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