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

const int mxn=1e6;
int n,m,q;

void solve() {
    cin >>n >>m >>q;
    set<int> r,c;
    while(q--) {
        int x,y; cin >>x >>y;
        ll ans=0;
        if(!r.count(x)) {
            ans +=m-sz(c);
        }
        r.insert(x);
        if(!c.count(y)) {
           ans +=n-sz(r);
        }
        c.insert(y);
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}