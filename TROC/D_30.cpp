#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod = 998244353;
int n,m;
int a[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    ll ans=1;
    int l=-1,lid=-1;
    bool allnull = 1;
    for(int i=0;i<n;i++) {
        if(a[i]!=-1 && l!=-1) {
            // kali
            ll len = i-lid;
            ll x = __builtin_popcount(a[i]^l);
            ans = (ans*fastexpo(len,x))%mod;
            l = -1;
            lid = -1;
        } else if(a[i]==-1) {
            if(i>0 && a[i-1]!=-1) {
                l = a[i-1];
                lid = i-1;
            }
        }
        if(a[i]!=-1) allnull=0;
    }
    if(allnull) {
        ans = fastexpo(2,m);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}