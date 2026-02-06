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

const int mxn=1e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> pref(n,0), suf(n,0);
    rep(i,0,n) {
        pref[i] = (i>0?pref[i-1]:0)+a[i];
    }
    per(i,n-1,-1) {
        suf[i] = (i+1<n?suf[i+1]:0)+a[i];
    }
    vector<int> mn1(n,1e5),mx1(n,-1e5);
    rep(i,0,n) {
        if(i>0) {
            min_self(mn1[i],mn1[i-1]);
            max_self(mx1[i],mx1[i-1]);
        }
        min_self(mn1[i],a[i]);
        max_self(mx1[i],a[i]);
    }
    vector<int> mn2(n,1e5), mx2(n,-1e5);
    per(i,n-1,-1) {
        if(i+1<n) {
            min_self(mn2[i],mn2[i+1]);
            max_self(mx2[i], mx2[i+1]);
        }
        min_self(mn2[i],a[i]);
        max_self(mx2[i],a[i]);
    }
    int ret = 0;
    rep(i,0,n-1) {
        max_self(ret, abs((pref[i]-mx1[i])-(suf[i+1]-mn2[i+1])));
        max_self(ret, abs((pref[i]-mn1[i]) - (suf[i+1]-mx2[i+1])));
    }
    cout <<ret <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}