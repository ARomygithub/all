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

const int mxn=3e5;
int n,t;
ll a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i] >>b[i];
    }
    vector<ll> ans(n,0);
    stack<pll> st;
    ll mx = 0;
    rep(i,0,n) {
        ll minu = 0;
        while(sz(st)) {
            auto [aj, bj] = st.top();
            if(bj==b[i]) {
                st.pop();
                a[i] = aj + a[i]-minu;
                minu = 0;
            } else {
                if(aj>a[i]) {
                    break;
                } else{
                    max_self(minu, aj);
                    st.pop();
                }
            }
        }
        st.push({a[i], b[i]});
        max_self(mx, a[i]);
        ans[i] = mx;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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