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

const int mxn=3e5;
int n,m,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    int rk = a[0];
    sort(a,a+n);
    sort(b,b+m);
    vector<ll> ans(m,-1);
    int udh = 0;
    rep(i,0,m) {
        udh += (b[i]<=rk);
    }
    rep(k,1,m+1) {
        int ct = m/k;
        int x = ct*(k-1);
        int ls = m-ct;
        if(udh<x) {
            ls = m-ct-(x-udh);
        } else {
            ls = m - max(0,ct*k-udh);
        }
        ll cur = 0;
        rep(j,0,ct) {
            if(ls>=m) {
                cur +=(ct-j);
                break;
            } else {
                int lwr = lower_bound(a,a+n, b[ls]) - a;
                cur += (n-lwr)+1;
                // ls = min(ls+k,m-ct+j+1);
                ls +=k;
            }
        }
        ans[k-1] = cur;
    }
    rep(i,0,m) {
        cout <<ans[i] <<" \n"[i==m-1];
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