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
ll n,q;
ll x;

void solve() {
    cin >>n >>q;
    while(q--) {
        cin >>x;
        ll ans = 0;
        ll r = x%(n+1);
        if(n==1) {
            if(x == 1) {
                ans = 1;
            }
        } else {
            if(r==0) {
                ll mx = (n/2);
                ll len = x/(n+1);
                if(len<=mx) {
                    ans = mx-len+1;
                }
            } else {
                if(r-1 <= (n/2)) {
                    if(r*(n+2)==x) {
                        ll odr = (n+1)/2;
                        // assert(odr>=r);
                        if(odr>=r) {
                            ans += odr - r;
                        }
                    }
                }
                ll len = x/(n+1);
                if(r <= (n+1)/2) {
                    ll pos = r*2-1;
                    if(pos-len*2 > 0) {
                        ans++;
                    }
                } else {
                    ll pos = (n+1 - r)*2;
                    if(pos + len*2 <=n) {
                        ans++;
                    }
                }
            }
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