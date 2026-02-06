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

int ask(vector<vi>& v) {
    cout <<sz(v[0]) <<" " <<sz(v[1]) <<" ";
    rep(i,0,sz(v[0])) {
        cout <<v[0][i] <<" ";
    }
    rep(i,0,sz(v[1])) {
        cout <<v[1][i] <<" \n"[i==sz(v[1])-1];
    }
    cout <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    int b = 0;
    while((1<<b) <=n) {
        b++;
    }
    int ans = 0;
    rep(i,0,b) {
        vector v(2,vi());
        rep(j,1,n+1) {
            v[(j>>i)&1].push_back(j);
        }
        if(sz(v[0])==0 || sz(v[1])==0) continue;
        max_self(ans, ask(v));
    }
    cout <<"-1 " <<ans <<"\n";
    cout <<flush;
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