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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5,mxb=59;
int n,q;
ll a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    while(q--) {
        ll k; cin >>k;
        vector<ll> b(n);
        rep(i,0,n) {
            b[i] = a[i];
        }
        ll ans=0;
        per(i,mxb,-1) {
            if(k<=0) break;
            ll temp=0;
            vector<ll> c(b.begin(),b.end());
            rep(j,0,n) {
                if(!((b[j]>>i)&1)) {
                    ll temp2 = (1ll<<i)-(b[j]%(1ll<<i));
                    temp +=temp2;
                    c[j] +=temp2;
                    if(temp>k) break;
                }
            }
            if(temp<=k) {
                k -=temp;
                b.swap(c);
                ans +=(1ll<<i);
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