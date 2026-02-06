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

const int mxn=2e5+1;
int n,k;
int p[mxn],pi[mxn];

void solve() {
    cin >>n >>k;
    rep(i,1,n+1) {
        cin >>p[i];
        pi[p[i]] = i;
    }
    set<int> s;
    int ans = n-1;
    for(int l=1,r=1;r<=n;r++) {
        s.insert(pi[r]);
        while(r+1 <= l+k-1) {
            r++;
            s.insert(pi[r]);
        }
        while(l< r-k+1) {
            s.erase(pi[l]);
            l++;
        }
        min_self(ans, *(--s.end()) - *(s.begin()));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}