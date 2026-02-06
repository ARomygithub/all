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

const int mxn=25e4;
int n,q,t;
int a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi pr(n+1,0);
    rep(i,1,n+1) {
        pr[i] = pr[i-1]+a[i-1];
    }
    set<int> st;
    rep(i,0,n-1) {
        if(a[i]==a[i+1]) {
            st.insert(i);
        }
    }
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        bool ok = (((r-l+1)%3)==0) && (((pr[r+1]-pr[l])%3)==0);
        if(ok) {
            auto it = st.lower_bound(l);
            int ans = (r-l+1)/3;
            if(it!=st.end() && (*it)<r) {
                ;
            } else {
                ans++;
            }
            cout <<ans <<"\n";
        } else {
            cout <<"-1\n";
        } 
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