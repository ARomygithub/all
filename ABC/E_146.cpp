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
int n,k;
int a[mxn];

void solve() {
    cin >>n >>k;
    vector<ll> pref(n);
    rep(i,0,n) {
        cin >>a[i];
        pref[i] = (i>0?pref[i-1]:0ll) + a[i]-1;
    }
    map<int,int> mp;
    mp[0]++;
    ll ans = 0;
    rep(i,0,n) {
        if(i>=k-1) {
            int prv = i-k>=0?pref[i-k]%k:0;
            mp[prv]--;
        }
        int cur = pref[i]%k;
        ans += mp[cur];
        mp[cur]++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}