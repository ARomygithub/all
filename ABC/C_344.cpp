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
int n,m,l,q;
int a[mxn],b[mxn],c[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    cin >>m;
    rep(i,0,m) {
        cin >>b[i];
    }
    cin >>l;
    rep(i,0,l) {
        cin >>c[i];
    }
    map<int,int> mp;
    rep(i,0,n) {
        rep(j,0,m) {
            rep(k,0,l) {
                mp[a[i]+b[j]+c[k]]++;
            }
        }
    }
    cin >>q;
    while(q--) {
        int x; cin >>x;
        if(mp.count(x)) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}