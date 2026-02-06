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

const int mxn=1e5,mxa=2e6;
ll n;
ll fp[mxa+1];

void solve() {
    cin >>n;
    ll ans = 0;
    for(ll x = 2; x*x<=n;x++) {
        bool ok = 0;
        ll px = fp[x];
        ll px2 = px*px;
        if((x%px2)==0) {
            if(x/px2 == px2) {
                ok = 1;
            }
        }
        if(ok) {
            ans++;
            continue;
        }
        if(x == fp[x]*fp[x/fp[x]] && fp[x]!=fp[x/fp[x]]) {
            ans++;
        }
    }
    cout <<ans <<"\n";
}

void init() {
    vector<bool> iscomp(mxa+1,0);
    rep(i,2,mxa+1) {
        if(!iscomp[i]) {
            fp[i] = i;
            for(ll j = 1ll*i*i;j<=mxa;j+=i) {
                if(fp[j]==0 || fp[j]>i) {
                    fp[j] = i;
                }
                iscomp[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}