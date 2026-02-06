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

const int mxn=2e5;
int n,t;
ll a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    int l=0,r=n-1;
    ll x=0;
    ll ans=0;
    while(l<r) {
        ll temp = min(a[l],a[r]-x);
        a[l] -=temp;
        ans +=temp;
        x +=temp;
        if(a[l]==0) {
            l++;
        }
        if(x==a[r]) {
            r--;
            ans++;
            x = 0;
        }
    }
    if(l==r) {
        // a[l] -=x;
        if(a[l] > x) {
            if(a[l]==1) {
                ans++;
            } else {
                a[l] -=x;
                ans += (a[l]+1)/2;
                ans++;
            }
        } else {
            ans++;
        }
    }
    cout <<ans <<"\n";
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