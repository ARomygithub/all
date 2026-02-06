#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
ll n,m,a,b,c;

// a(m.a+n)/a + bm = c; 0-a-1 = n
void solve() {
    cin >>a >>b >>c;
    ll ans = -1;
    ll l = 0, r = c;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll temp = mid + b*(mid/a);
        if(temp == c) {
            ans = mid;
            r = mid-1;
        } else if(temp<c) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    if(ans==-1) {
        cout <<"-1\n";
    } else {
        ll temp = __gcd(ans,a);
        ans /=temp;
        a /=temp;
        cout <<ans <<"/" <<a <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}