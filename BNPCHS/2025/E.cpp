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
int n;

void solve() {
    cin >>n;
    vi mp(mxn+1,0);
    rep(i,0,n) {
        int ai; cin >>ai;
        mp[ai]++;
    }
    ll ans = 1ll*n*(n-1)/2;
    for(auto& v: mp) {
        ans -= 1ll*v*(v-1)/2;
    }
    rep(m,1,mxn+1) {
        for(int a=m;a<=mxn;a+=m) {
            int b = a+m;
            if(b<=mxn && m==(b^a)) {
                ans -= 1ll*mp[a]*mp[b];
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}