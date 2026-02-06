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
int n,m,k;
int l[mxn],r[mxn],a[mxn],b[mxn]; 

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>l[i];
    }
    rep(i,0,n) {
        cin >>r[i];
    }
    cin >>m;
    rep(i,0,m) {
        cin >>a[i]; a[i]--;
    }
    rep(i,0,m) {
        cin >>b[i]; b[i]--;
    }
    cin >>k;
    map<int,int> mp;
    rep(i,0,m) {
        mp[l[a[i]]]++;
    }
    ll ans = 0;
    rep(i,0,m) {
        ans += mp[k-r[b[i]]];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}