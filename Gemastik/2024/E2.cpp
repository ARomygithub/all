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

const int mxn=1000,mxa=1e9;
const ll mod=1e9+7;
int n,k;
vector<int> a;
ll ans = 0;

int getbit(int rat) {
    int ct = 1;
    while((1<<(ct-1)) < rat) {
        ct++;
    }
    return ct;
}

void doRec(int ls, int cur, int szi) {
    rep(i,cur,n) {
        if(szi+1>=k) {
            ans = (ans+1)%mod;
        }
        auto it = lower_bound(a.begin(),a.end(),a[ls]+a[i]);
        int rat = mxa/(a[ls]+a[i]);
        if(getbit(rat)*2+szi < k) return;
        if(it!=a.end()) {
            int r = it-a.begin();
            doRec(i, r, szi+1);
        }
    }
}

void solve() {
    cin >>n >>k;
    a.resize(n);
    rep(i,0,n) {
        cin >>a[i];
    }
    if(k==2) {
        ans += 1ll*(n)*(n-1)/2;
    }
    ans %=mod;
    rep(i,0,n) {
        rep(j,i+1,n) {
            auto it = lower_bound(a.begin(),a.end(), a[i]+a[j]);
            if(it!=a.end()) {
                int r = it-a.begin();
                doRec(j, r, 2);
            }
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