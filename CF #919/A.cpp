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
int n,t;

void solve() {
    cin >>n;
    set<int> s;
    int l=1,r=1e9;
    rep(i,0,n) {
        int qt, x; cin >>qt >>x;
        if(qt==1) {
            max_self(l,x);
        } else if(qt==2) {
            min_self(r,x);
        } else {
            s.insert(x);
        }
    }
    int ans=0;
    if(l<=r) {
        ans = r-l+1;
        auto it = s.upper_bound(r);
        auto it2 = s.lower_bound(l);
        ans -=distance(it2,it);
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