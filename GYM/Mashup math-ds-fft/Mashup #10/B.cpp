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

const int mxn=3e5;
int n,m,t;

void solve() {
    cin >>n >>m;
    vector c(n, vector<ll>(m));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>c[i][j];
        }
    }
    map<ll,vi> mp;
    rep(i,0,n) {
        ll pr = 0;
        ll cur = 0;
        rep(j,0,m) {
            pr += c[i][j];
            cur += pr;
        }
        mp[cur].push_back(i);
    }
    ll s = -1, sk=-1;
    int k = -1;
    for(auto& [si,ve]: mp) {
        if(sz(ve)==1) {
            sk = si;
            k = ve[0];
        } else {
            s = si;
        }
    }
    cout <<k+1 <<" " <<s-sk <<"\n";
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