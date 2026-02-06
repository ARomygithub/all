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
int n,k,t;

void solve() {
    cin >>n >>k;
    vi a(k,0);
    int bts = k;
    per(bit,29,-1) {
        if((1<<bit)>n) continue;
        if((n>>bit)&1) {
            rep(i,0,k) {
                a[i] += (1<<bit);
            }
            if((k%2)==0) {
                if(bts>0) {
                    a[bts-1] -= (1<<bit);
                    bts--;
                } else {
                    a[k-1] -= (1<<bit);
                }
            }
        } else {
            rep(i,bts,k) {
                a[i] += (1<<bit);
            }
            if((k-bts)%2) {
                a[k-1] -= (1<<bit);
            }
        }
    }
    int xr = 0;
    rep(i,0,k) {
        xr ^= a[i];
    }
    assert(xr==n);
    rep(i,0,k) {
        cout <<a[i] <<" \n"[i==k-1];
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