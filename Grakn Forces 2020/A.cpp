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

const int mxn=1e2;
int n,t;
int a[mxn],b[mxn],c[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    rep(i,0,n) {
        cin >>c[i];
    }
    vector<int> p;
    rep(i,0,n) {
        int l=-1,r=-1;
        if(i>0) {
            l = p.back();
        }
        if(i==n-1) {
            r = p[0];
        }
        if(a[i]!= l && a[i]!=r) {
            p.push_back(a[i]);
            continue;
        }
        if(b[i]!= l && b[i]!=r) {
            p.push_back(b[i]);
            continue;
        }
        if(c[i]!= l && c[i]!=r) {
            p.push_back(c[i]);
            continue;
        }                
    }
    rep(i,0,sz(p)) {
        cout <<p[i] <<" \n"[i==sz(p)-1];
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