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

const int mxn=30;
int n,m,q,x[mxn];
vector<pii> ed[3];

void solve() {
    cin >>n >>m >>q;
    rep(i,0,n) {
        cin >>x[i];
    }
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(min(u,v)>=(n/2)) {
            ed[1].push_back({u,v});
        } else if(max(u,v)<(n/2)) {
            ed[0].push_back({u,v});
        } else {
            ed[2].push_back({u,v});
        }
    }
    set<pii> s1,s2;
    rep(iq,0,q) {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}