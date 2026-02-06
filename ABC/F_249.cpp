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

const int mxn=2e5;
int n,k;
int t[mxn],y[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>t[i] >>y[i];
    }
    multiset<int> s;
    ll skip = 0;
    ll sum = 0;
    int ct1 = 0;
    ll ans = -1e18;
    per(i,n-1,-1) {
        if(t[i]==1) {
            max_self(ans, y[i]+sum-skip);
            ct1++;
            if(sz(s)>k-ct1) {
                if(k-ct1<0) {
                    break;
                }
                auto it = (--s.end());
                skip -= *it;
                s.erase(it);
            }
        } else {
            sum += y[i];
            if(y[i]<0ll) {
                skip += y[i];
                s.insert(y[i]);
                if(sz(s)>k-ct1) {
                    auto it = (--s.end());
                    skip -= *it;
                    s.erase(it);
                }
            }
        }
    }
    if(k-ct1>=0) {
        max_self(ans, sum-skip);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}