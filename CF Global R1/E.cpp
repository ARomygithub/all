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

const int mxn=1e5;
int n;
int c[mxn],t[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>c[i];
    }
    rep(i,0,n) {
        cin >>t[i];
    }
    if(c[0]!=t[0]) {
        cout <<"No\n";
        return;
    }
    multiset<int> ms1,ms2;
    rep(i,1,n) {
        ms1.insert(c[i]-c[i-1]);
    }
    rep(i,1,n) {
        ms2.insert(t[i]-t[i-1]);
    }
    for(auto it1=ms1.begin(),it2=ms2.begin(); it1!=ms1.end();it1++,it2++) {
        if((*it1)!=(*it2)) {
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}