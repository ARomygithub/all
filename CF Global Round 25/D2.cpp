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

const int mxn=1e5;
int t;
ll n,k;

bool sol(vector<ll>& ans, ll nn, ll kk, int ct=0) {
    // cout <<"sol" <<endl;
    if(nn<kk) return 0;
    ll nk = nn/kk;
    if(kk == (nn/nk)) {
        ans.push_back(nk);
        return 1;
    } else if(ct+2<=60) {
        for(ll i=nk+1,la;i<=nn;i=la+1) {
            la = nn/(nn/i);
            if(sol(ans,(nn%i),kk-(nn/i),ct+1)) {
                ans.push_back(i);
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    cin >>n >>k;
    if(n<k) {
        cout <<"NO\n";
        return;
    }
    vector<ll> ans;
    bool ok = sol(ans, n, k);
    if(ok) {
        reverse(ans.begin(),ans.end());
        cout <<"YES\n";
        cout <<sz(ans) <<"\n";
        rep(i,0,sz(ans)) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    } else {
        cout <<"NO\n";
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