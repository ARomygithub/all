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

const int mxn=2e5;
int n,q,t;
int a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    multiset<int> ms1,ms2;
    rep(i,0,n) {
        ms1.insert(a[i]+i);
        ms2.insert(a[i]-i);
    }
    auto getans = [&]() -> ll {
        ll ret = 0;
        ret += max((*(--ms1.end()))-(*ms1.begin()), *(--ms2.end())-(*ms2.begin()));
        return ret;
    };
    cout <<getans() <<"\n";
    while(q--) {
        int p,x; cin >>p >>x; p--;
        ms1.erase(ms1.find(a[p]+p));
        ms2.erase(ms2.find(a[p]-p));
        a[p] = x;
        ms1.insert(a[p]+p);
        ms2.insert(a[p]+p);
        cout <<getans() <<"\n";
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