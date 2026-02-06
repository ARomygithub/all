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
    vi st;
    set<int> sval;
    rep(i,1,30) {
        sval.insert((1<<i)+1);
    }
    rep(i,0,n) {
        if(sval.count(a[i])) {
            st.push_back(i);
        }
    }
    vi pr(n+1,0);
    rep(i,1,n+1) {
        int cur = 1;
        int u = 2;
        while(u<a[i-1]) {
            cur++;
            u *=2;
        }
        pr[i] = pr[i-1] + cur; 
    }
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        int ans = pr[r+1]-pr[l];
        auto m  = upper_bound(all(st),r) - lower_bound(all(st),l);
        ans -= (m+1)/2;
        cout <<ans <<"\n";
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