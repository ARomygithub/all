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

const int mxn=100;
int n;
int a[mxn];
ll x;

void solve() {
    cin >>n >>x;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 1e18;
    rep(i,1,n+1) {
        vector mx(i+1, vector<ll>(i,-1ll));
        mx[0][0] = 0ll;
        rep(j,0,n) {
            vector mx_new(i+1, vector<ll>(i,-1ll));
            rep(k,0,i+1) {
                rep(l,0,i) {
                    max_self(mx_new[k][l], mx[k][l]);
                    if(mx[k][l]>=0 && k<i) {
                        max_self(mx_new[k+1][(l+a[j])%i], mx[k][l]+a[j]);
                    }
                }
            }
            mx.swap(mx_new);
        }
        if(mx[i][x%i]>=0) {
            ll temp = x - mx[i][x%i];
            temp /= i;
            min_self(ans, temp);
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