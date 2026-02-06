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
int t;
ll x,m;

void solve() {
    cin >>x >>m;
    ll ans = 0;
    rep(y,1,min(x+1,m+1)) {
        ll xy = x^y;
        if((xy%x)==0 || (xy%y)==0) {
            ans++;
        }
    }
    ll ri1 = -1;
    ll l = 1,r= ((m/x)+1)/2;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = x ^ (x*mid*2);
        if(cur<=m) {
            ri1 = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    } 
    if(ri1!=-1) {
        ans += ri1;
        // cout <<ri1 <<endl;
    }
    ll ri2 = -1;
    l = 1, r = (m/x)/2;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = x ^ ((mid*2+1)*x);
        if(cur<=m) {
            ri2 = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    if(ri2!=-1) {
        ans += ri2;
        // cout <<ri2 <<endl;
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