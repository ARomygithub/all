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

const int mxn=4e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> r(n,n);
    map<int,int> idx;
    rep(i,0,n) {
        rep(j,1,30) {
            int prv = a[i]-(1<<j);
            int nx = a[i]+(1<<j);
            if(idx.count(prv)) {
                min_self(r[idx[prv]], i);
            }
            if(idx.count(nx)) {
                min_self(r[idx[nx]], i);
            }
        }
        idx[a[i]] = i;
    }
    vector<int> r0(n),rp(n),rn(n);
    per(i,n-1,-1) {
        r0[i] = i;
        rp[i] = i;
        rn[i] = i;
        if(i<n-1) {
            min_self(r[i], r[i+1]);
            if(a[i+1]==a[i]) {
                max_self(r0[i], r0[i+1]);
                max_self(rp[i], rp[i+1]);
                max_self(rn[i], rn[i+1]);
            } else if(a[i+1]==a[i]-1) {
                max_self(rn[i], rp[i+1]);
            } else if(a[i+1]==a[i]+1) {
                max_self(rp[i], rn[i+1]);
            }
        }
    }
    ll ans = 0;
    rep(i,0,n) {
        // cout <<"i " <<i <<endl;
        int tr = i;
        max_self(tr, max(r0[i],rn[i]));
        max_self(tr, rp[i]);
        ans += n-r[i];
        min_self(tr, r[i]-1);
        // cout <<tr <<" " <<r[i] <<endl;
        ans += (tr-i+1);
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