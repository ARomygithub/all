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

const int mxn=1e5;
int n,m,t;
int a[mxn+1];

void solve() {
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector<int> pref(n+1,0), suf(n+1,0);
    rep(i,2,n+1) {
        pref[i] = pref[i-1];
        if(i-1==1 || (abs(a[i-1]-a[i])<abs(a[i-2]-a[i-1]))) {
            pref[i]++;
        } else {
            pref[i] +=a[i]-a[i-1];
        }
    }
    per(i,n-1,0) {
        suf[i] = suf[i+1];
        if(i+1==n || (abs(a[i]-a[i+1])<abs(a[i+1]-a[i+2]))) {
            suf[i]++;
        } else {
            suf[i] +=a[i+1]-a[i];
        }
    }
    cin >>m;
    while(m--) {
        int x,y; cin >>x >>y;
        if(x<=y) {
            cout <<pref[y]-pref[x] <<"\n";
        } else {
            cout <<suf[y]-suf[x] <<"\n";
        }
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