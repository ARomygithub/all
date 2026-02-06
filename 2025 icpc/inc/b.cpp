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

const int mxn=2e5;
int n,m,t;
int a[mxn];

void solve() {
    cin >>n >>m;
    vector<pii> ans;
    rep(i,0,n) {
        cin >>a[i];
    }
    if(m<n-1 || a[0]!=1) {
        cout <<"-1 -1\n";
        return;
    }
    m -= (n-1);
    int le = 0;
    for(int ri=1;ri<n;) {
        int j = ri+1;
        while(j<n && a[j-1]<a[j]) {
            j++;
        }
        rep(k,ri,j) {
            ans.push_back({a[le],a[k]});
        }
        int cur = le+1;
        while(cur<ri && m>0) {
            ans.push_back({a[le],a[cur]});
            cur++;
            m--;
        }
        ri = j;
        le++;
    }
    while(m>0 && le<n) {
        int cur = le+1;
        while(cur<n && m>0) {
            ans.push_back({a[le],a[cur]});
            cur++;
            m--;
        }
        le++;
    }
    if(m>0) {
        cout <<"-1 -1\n";
        return;
    }
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}