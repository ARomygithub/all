#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

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

const int mxn=1e5,ajaib=1e4;
const ll mod=1e9+9;
int n,t,h0,a,b,qi,c;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>t >>h0 >>a >>b >>qi;
    if(t==0) {
        cout <<"0 1\n";
        return;
    }
    set<int> allow;
    int ui = h0;
    vector<int> vallow2;
    int n10 = fastexpo(10,n);
    while(true) {
        if(allow.find(ui)!=allow.end()) {
            break;
        }
        allow.insert(ui);
        vallow2.push_back(ui%n10);
        ui = (1ll*ui*a+b)%(1ll*qi);
    }
    int l=0,r=sz(vallow2);
    int ansfi=-1, ansse = -1;
    while(l<=r) {
        int mid = (l+r)/2;
        set<int> allow2;
        allow2.insert(t);
        rep(i,0,mid) {
            allow2.insert(vallow2[i]);
        }
        vector<pii> dp(n10,{1e9,-1});
        queue<int> q;
        dp[0] = {0,1};
        q.push(0);
        while(sz(q)) {
            int u = q.front(); q.pop();
            // cout <<u <<" " <<dp[u].fi <<" " <<dp[u].se <<"\n";
            int temp = u;
            if(u==t) break;
            rep(i,0,n) {
                int i10 = fastexpo(10,i);
                int v1 = u- (temp%10)*i10;
                int tempBaru = ((temp%10)+1)%10;
                v1 = v1 + tempBaru*i10;
                if(allow2.find(v1)!=allow2.end()) {
                    if(dp[v1].fi>dp[u].fi+1) {
                        dp[v1].fi = dp[u].fi+1;
                        dp[v1].se = dp[u].se;
                        q.push(v1);
                    } else if(dp[v1].fi==dp[u].fi+1) {
                        dp[v1].se = (dp[v1].se+dp[u].se)%mod;
                    }
                }
                int v2 = u - (temp%10)*i10;
                tempBaru = ((temp%10)-1+10)%10;
                v2 = v2 + tempBaru*i10;
                if(allow2.find(v2)!=allow2.end()) {
                    if(dp[v2].fi>dp[u].fi+1) {
                        dp[v2].fi = dp[u].fi+1;
                        dp[v2].se = dp[u].se;
                        q.push(v2);
                    } else if(dp[v2].fi==dp[u].fi+1) {
                        dp[v2].se = (dp[v2].se+dp[u].se)%mod;
                    }
                }
                temp /=10;
            }
        }
        if(dp[t].fi==1e9) {
            l = mid+1;
        } else {
            r = mid-1;
            ansfi = dp[t].fi, ansse = dp[t].se;
        }
    }
    if(ansfi==-1) {
        cout <<"-1\n";
    } else {
        cout <<ansfi <<" " <<ansse <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>c;
    while(c--) {
        solve();
    }
}