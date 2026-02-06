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
ll n,s,k,h;
ll p[mxn],t[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>p[i];
    }
    rep(i,0,n) {
        cin >>t[i];
    }
    cin >>s >>k >>h;
    ll l=0,r=0;
    rep(i,0,n) {
        max_self(r, p[i]+t[i]*h);
    }
    ll ans = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        vector<ll> y(n);
        rep(i,0,n) {
            ll dif = (p[i]+t[i]*h)-mid;
            y[i] = max(0ll, (dif+s-1)/s);
        }
        ll sy = 0;
        rep(i,0,n) {
            sy += y[i];
        }
        bool ok = 1;
        if(sy>k*h) {
            ok = 0;
        }
        if(ok) {
            multiset<ll> ms;
            rep(i,0,h) {
                rep(j,0,k) {
                    ms.insert(i);
                }
            }
            rep(i,0,n) {
                rep(j,1,y[i]+1) {
                    // s*j <= p+t*mini
                    ll mini = (s*j-p[i] + t[i]-1)/t[i];
                    auto it = ms.lower_bound(mini);
                    if(it==ms.end()) {
                        ok = 0;
                        break;
                    } else {
                        ms.erase(it);
                    }
                }
                if(!ok) break;
            }
        }
        if(ok) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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
    /*
    hari ke -x: p+t*x.
    1 hari: kurangi yg besar, ulangi sampe k kali
    2 hari: 
    bsta
    O(47*_)
    dif1, dif2, ..., difn
    dari k*h: sebagian -s, sebagian -r (r<s).
    penuhi dif satu per satu. 
    -r _
    _ -s

    _ -s
    -s _

    asumsi perlu -s semua, trs coba submit saja.
    y1, .., yn
    sigma y_i <= k*h
    lalu kasih yg paling awal.
    */