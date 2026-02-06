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
int n,q;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    rep(i,0,n) {
        ans += a[i];
    }
    cin >>q;
    map<pii,int> mp;
    rep(i,0,q) {
        int s,t,u; cin >>s >>t >>u; s--,u--;
        if(mp.count({s,t})) {
            int c = mp[{s,t}];
            a[c]++;
            if(a[c]>0) {
                ans++;
            }
            mp.erase({s,t});
        }
        if(u>=0) {
            a[u]--;
            if(a[u]>=0) {
                ans--;
            }
            mp[{s,t}] = u;
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}