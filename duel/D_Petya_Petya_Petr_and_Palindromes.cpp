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
int n,k,t;
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    int mid = k/2;
    ll ans = 1ll*(n-k+1)*mid;
    map<pii,vi> mp;
    rep(i,0,n) {
        mp[{a[i],i%2}].push_back(i);
    }
    rep(i,0,n) {
        if(i >= n-1-mid) continue;
        int ml = max(i+1, mid);
        int le = ml + (ml-i);
        int mr = min(i+mid,n-1-mid);
        int ri = mr + (mr-i);
        pii cur = {a[i],i%2};
        ans -= (upper_bound(all(mp[cur]), ri) - lower_bound(all(mp[cur]), le));
        // cerr << ans <<endl;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    // while(t--) {
        solve();
    // }
}