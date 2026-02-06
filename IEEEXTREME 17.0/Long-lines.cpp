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

const int mxn=1e7;
int n,a,c,q;
int h[mxn];

void solve() {
    cin >>n >>h[0] >>a >>c >>q;
    rep(i,1,n) {
        h[i] = (1ll*h[i-1]*a+c)%q;
        // cout <<h[i] <<"\n";
    }
    ll ans=0;
    stack<pii> st;
    per(i,n-1,-1) {
        if(sz(st)) {
            int last=-1;
            while(sz(st) && st.top().fi<=h[i]) {
                if(st.top().fi==h[i]) last=st.top().se; 
                st.pop();
            }
            if(last==-1) {
                if(sz(st)) {
                    last = st.top().se;
                } else {
                    last = n-1;
                }
            }
            ans += last-i;
            st.push({h[i],i});
        } else {
            st.push({h[i],i});
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