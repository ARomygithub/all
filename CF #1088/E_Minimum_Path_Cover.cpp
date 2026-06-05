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
int n,t;
// vi adj[mxn];
ll a[mxn];

void solve() {
    cin >>n;
    vi f(n,0);
    per(i,n-1,-1) {
        cin >>a[i];
        int k; cin >>k;
        int sm = 0;
        ll cur = 1;
        rep(j,0,k) {
            int cj; cin >>cj; cj--;
            sm += f[cj];
            ll tmp = __gcd(a[i], a[cj]);
            ll d = __gcd(tmp, cur);
            cur = d*(cur/d)*(tmp/d);
        }
        if(cur==1) {
            sm++;
        } else {
            a[i] = cur;
        }
        f[i] = sm;
        cout <<f[i] <<"\n" <<flush;
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