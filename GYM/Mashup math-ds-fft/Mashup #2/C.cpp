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

const int mxn=1e6;
int n;
int lp[mxn+1];

void solve() {
    cin >>n;
    int l = n-(lp[n]-1);
    int ans = 1e9;
    rep(i,l,n+1) {
        if(i==lp[i]) continue;
        min_self(ans, i-(lp[i]-1));
    }
    cout <<ans <<"\n";
}

void init() {
    vector<bool> isComp(mxn+1,0);
    rep(i,2,mxn+1) {
        if(!isComp[i]) {
            max_self(lp[i],i);
            for(ll j=i*2;1ll*j<=mxn;j+=i) {
                max_self(lp[j], i);
                isComp[j] = 1;
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