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
int n,q;

void solve() {
    cin >>n >>q;
    vector<int> a(n);
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a.begin(),a.end());
    while(q--) {
        int b,k; cin >>b >>k;
        int ans = -1;
        int l=0,r=2e8;
        while(l<=r) {
            int mid = (l+r)/2;
            auto it1 = lower_bound(a.begin(),a.end(),b-mid);
            auto it2 = upper_bound(a.begin(),a.end(),b+mid);
            if((it2-it1) >=k) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}