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

const int mxn=40,mxt=1e9;
int n,t;
ll a[mxn];

void solve() {
    cin >>n >>t;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s1,s2;
    // mp1[0]++; mp2[0]++;
    int hn = n/2;
    rep(i,0,(1<<hn)) {
        ll temp = 0;
        rep(j,0,hn) {
            if((i>>j)&1) {
                temp += a[j];
            }
        }
        if(temp<=mxt) {
            s1.insert(temp);
        }
    }
    rep(i,0,(1<<(n-hn))) {
        ll temp = 0;
        rep(j,0,(n-hn)) {
            if((i>>(j))&1) {
                temp += a[j+hn];
            }
        }
        if(temp<=mxt) {
            s2.insert(temp);
        }
    }
    int ans = 0;
    for(auto si : s1) {
        if(si>t) break;
        auto it = --s2.upper_bound(t-si);
        max_self(ans, si+(*it));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}