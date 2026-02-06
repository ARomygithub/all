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

const int mxn=1e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    multiset<int> ms;
    vi suf(n);
    suf[n-1] = a[n-1];
    per(i,n-2,-1) {
        suf[i] = min(suf[i+1],a[i]);
    }
    vi ans;
    rep(i,0,n) {
        if(a[i]==suf[i]) {
            if(sz(ms) && *(ms.begin()) < a[i]) {
                ms.insert(a[i]+1);
            } else {
                ans.push_back(a[i]);
            }
        } else {
            ms.insert(a[i]+1);
        }
    }
    for(auto msi : ms) {
        ans.push_back(msi);
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