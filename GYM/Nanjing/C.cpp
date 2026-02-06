#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll p,m;

void solve() {
    cin >>p >>m;
    ll ans = 0;
    ll l=0,r=m/(p*2)+1;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = (p*(mid*2+1) + 1)^(p-1);
        if(cur <=m) {
            ans = mid+1;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    ll ad = 0;
    l = 0, r = (m/(p*2))+2;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = (p*mid*2 + 1)^(p-1);
        if(cur<=m) {
            ad = mid+1;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    ans += ad;
    cout <<ans <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // int tc = 1;
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
}