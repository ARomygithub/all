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
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans=0;
    vector<int> idx1(n,0);
    set<int> s1;
    rep(i,0,n) {
        if(s1.find(a[i])==s1.end()) {
            idx1[i]++;
        }
        s1.insert(a[i]);
    }
    rep(i,0,n) {
        idx1[i] += (i>0?idx1[i-1]:0);
    }
    set<int> s2;
    per(i,n-1,-1) {
        if(s2.find(a[i])==s2.end()) {
            ans +=idx1[i];
        }
        s2.insert(a[i]);
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