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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
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
    int n10 = fastexpo(10,n);
    vector<int> idx(n10,1e9);
    int idxCt=0;
    while(true) {
        if(allow.find(ui)!=allow.end()) {
            break;
        }
        allow.insert(ui);
        min_self(idx[ui%n10], idxCt);
        idxCt++;
        ui = (1ll*ui*a+b)%(1ll*qi);
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> idxDp(n10,1e9);
    idx[0] = -1;
    idxDp[0] = -1;
    pq.push({-1,0});
    int len=-1;
    // int ctLoop=0;
    while(sz(pq)) {
        auto [idxDpi, u] = pq.top(); pq.pop();
        // ++ctLoop;
        // if(ctLoop>=mxLoop) {
        //     break;
        // }
        if(u==t) {
            len = idxDpi+1;
            break;
        }
        if(idxDp[u]<idxDpi) continue;
        int temp=u;
        int i10 = 1;
        rep(i,0,n) {
            int v1 = u- (temp%10)*i10;
            int tempBaru = ((temp%10)+1)%10;
            v1 = v1 + tempBaru*i10;
            if(v1==t) {
                pq.push({idxDpi,t});
                temp /=10;
                i10 *=10;
                break;
            }
            if(idx[v1]<1e9) {
                int idxDpv = max(idxDpi,idx[v1]);
                if(idxDp[v1]>idxDpv) {
                    idxDp[v1] = idxDpv;
                    pq.push({idxDp[v1],v1});
                }
            }
            int v2 = u - (temp%10)*i10;
            tempBaru = ((temp%10)-1+10)%10;
            v2 = v2 + tempBaru*i10;
            if(v2==t) {
                pq.push({idxDpi,t});
                temp /=10;
                i10 *=10;
                break;
            }
            if(idx[v2]<1e9) {
                int idxDpv = max(idxDpi,idx[v2]);
                if(idxDp[v2]>idxDpv) {
                    idxDp[v2] = idxDpv;
                    pq.push({idxDp[v2],v2});
                }
            }
            temp /=10;
            i10 *=10;
        }        
    }
    if(len==-1) {
        cout <<"-1\n";
        return;
    }
    idx[t] = -1;
    vector<pii> dp(n10,{1e9,-1});
    queue<int> q;
    dp[0] = {0,1};
    q.push(0);
    while(sz(q)) {
        int u = q.front(); q.pop();
        // cout <<u <<" " <<dp[u].fi <<" " <<dp[u].se <<"\n";
        int temp = u;
        if(u==t) break;
        int i10 = 1;
        rep(i,0,n) {
            int v1 = u- (temp%10)*i10;
            int tempBaru = ((temp%10)+1)%10;
            v1 = v1 + tempBaru*i10;
            if(idx[v1]<len) {
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
            if(idx[v2]<len) {
                if(dp[v2].fi>dp[u].fi+1) {
                    dp[v2].fi = dp[u].fi+1;
                    dp[v2].se = dp[u].se;
                    q.push(v2);
                } else if(dp[v2].fi==dp[u].fi+1) {
                    dp[v2].se = (dp[v2].se+dp[u].se)%mod;
                }
            }
            temp /=10;
            i10 *=10;
        }
    }
    cout <<dp[t].fi <<" " <<dp[t].se <<"\n";
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