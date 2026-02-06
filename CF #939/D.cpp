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

const int mxn=18;
int n;
int a[mxn];

void add(int l, int r, vector<pii>& ans) {
    // cout <<"tes" <<endl;
    per(i,r-1,l) {
        add(l,i,ans);
    }
    if(r==l+1) {
        ans.push_back({r,r});
    } else {
        ans.push_back({l,r});
        ans.push_back({l,r-1});
    }
}

void make_ans(int l, int r, vector<pii>& ans) {
    bool ada0=0, all0 = 1;
    rep(i,l,r+1) {
        ada0 = ada0 || (a[i]==0);
        all0 = all0 && (a[i]==0);
    }
    if(!all0) {
        if(ada0) {
            ans.push_back({l,r});
            ans.push_back({l,r});
        } else {
            ans.push_back({l,r});
        }
    }
    per(i,r,l) {
        add(l,i,ans);
    }
    ans.push_back({l,r});
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> dp(n,0);
    vector<int> p(n,-1);
    rep(i,0,n) {
        dp[i] = a[i]+(i>0?dp[i-1]:0);
        per(j,i,-1) {
            int len = i-j+1;
            if(len*len+(j>0?dp[j-1]:0) >dp[i]) {
                dp[i] = len*len + (j>0?dp[j-1]:0);
                p[i] = j;
            }
        }
    }
    cout <<dp[n-1] <<" " <<flush;
    vector<pii> ans;
    int u = n-1;
    while(u>=0) {
        if(p[u]==-1) {
            u--;
        } else {
            int l = p[u];
            make_ans(l,u,ans);
            u = l-1;
        }
    }
    cout <<sz(ans) <<"\n" <<flush;
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi+1 <<" " <<ans[i].se+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}