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
int n,k;

void solve() {
    cin >>n >>k;
    vector<int> a(n), b(k);
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,k) {
        cin >>b[i];
    }
    sort(a.begin(),a.end());
    int ans = -1;
    int l = 0, r = min(n,k-n);
    multiset<pii> mb;
    rep(i,0,k) {
        mb.insert({b[i],i});
    }
    while(l<=r) {
        int mid = (l+r)/2;
        multiset<int> ms;
        rep(i,0,n-mid) {
            ms.insert(8*a[i]);
        }
        rep(i,n-mid,n) {
            ms.insert(6*a[i]);
            ms.insert(2*a[i]);
        }
        bool ok = 1;
        pii ls = {-1,-1};
        while(sz(ms)) {
            pii srch = {*ms.begin(), -1};
            if(ls>srch) {
                srch = ls;
            }
            auto it = mb.lower_bound(srch);
            if(it==mb.end()) {
                ok = 0;
                break;
            } else {
                ls = *it;
                ls.se++;
            }
            ms.erase(ms.begin());
        }
        // cout <<l <<" " <<r <<" " <<mid <<" " <<ok <<endl;
        if(ok) {
            ans = n+mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}