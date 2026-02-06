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

const int mxn=2e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = -1e18;
    if(n%2) {
        vector<ll> suf(n,0);
        ll t1=0,t2=0;
        for(int i=n-2;i>=0;i-=2) {
            t1 = max(t1+a[i], t2+a[i]);
            t2 += a[i+1];
            suf[i] = max(t1,t2);
        }
        t1 = 0, t2= 0;
        max_self(ans, suf[1]);
        // cout <<suf[1] <<endl;
        for(int i=1;i<n;i+=2) {
            t2 = max(t2+a[i], t1+a[i]);
            t1 += a[i-1];
            max_self(ans, max(t1,t2)+(i+2<n?suf[i+2]:0ll));
            // cout <<max(t1,t2)+(i+2<n?suf[i+2]:0ll) <<endl;
        }
    } else {
        ll t1 = 0, t2=0;
        rep(i,0,n) {
            if(i%2) {
                t2 = max(t2+a[i],t1+a[i]);
                t1 += a[i-1];
            } 
        }
        ans = max(t1,t2);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}