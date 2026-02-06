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
int n,k,a[mxn],b[mxn],c[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    rep(i,0,n) {
        cin >>c[i];
    }
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    sort(c,c+n,greater<int>());
    int k3 = 80;
    int l = 1, r = 80;
    while(l<=r) {
        int mid = (l+r)/2;
        if(mid*mid*mid>=k) {
            k3 = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    ll lwr = 1ll*a[k3-1]*b[k3-1]+1ll*a[k3-1]*c[k3-1]+1ll*b[k3-1]*c[k3-1];
    multiset<ll> ms;
    bool oki = 1;
    rep(i,0,n) {
        bool okj = 1;
        rep(j,0,n) {
            rep(m,0,n) {
                ll cur = 1ll*a[i]*b[j]+1ll*b[j]*c[m]+1ll*a[i]*c[m];
                if(cur<=lwr) {
                    if(m==0) {
                        okj = 0;
                    }
                    if(m==0 && j==0) {
                        oki = 0;
                    }
                    break;
                }
                ms.insert(cur);
                if(sz(ms)>k) {
                    ms.erase(ms.begin());
                    lwr = *ms.begin();
                }
            }
            if(!okj) break;
        }
        if(!oki) break;
    }
    cout <<lwr <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}