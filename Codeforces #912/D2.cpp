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

const int mxn=1e6,mxb=20;
int n,q;
int a[mxn], cta[1<<mxb];
ll dp[1<<mxb][mxb];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll bts=0;
    rep(i,0,n) {
        bts +=(1<<20)-a[i];
    }
    rep(i,0,n) {
        cta[a[i]]++;
        ll sum=0;
        rep(j,0,mxb) {
            sum +=a[i]&(1<<j);
            dp[a[i]][j] +=sum;
        }
    }
    rep(i,0,mxb) {
        rep(j,0,1<<mxb) {
            if(!((j>>i)&1)) {
                cta[j] +=cta[j+(1<<i)];            
            }
        }
    }
    rep(i,0,mxb) {
        rep(j,0,1<<mxb) {
            if(!((j>>i)&1)) {
                rep(l,0,mxb) {
                    dp[j][l] +=dp[j+(1<<i)][l];
                }
            }
        }
    }
    while(q--) {
        ll k; cin >>k;
        if(k>=bts) {
            k -=bts;
            ll ans = (1ll<<20)+(k/n);
            cout <<ans <<"\n";  
        } else {
            int mask=0;
            per(i,mxb-1,-1) {
                if(k<=0) break;
                ll temp = 1ll*(n-cta[mask+(1<<i)])*(1<<i);
                temp -= dp[mask][i]-dp[mask+(1<<i)][i];
                if(k>=temp) {
                    k -=temp;
                    mask +=1<<i;
                }
            }
            cout <<mask <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}