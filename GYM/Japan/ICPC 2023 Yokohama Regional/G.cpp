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

const int mxn=3e5;
const ll mod = 998244353;
int n;
bool flag[mxn+1];
vector<ll> dp[mxn+1];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

ll iv6 = inv(6);
pii getPos(int u) {
    pii ret = {u/6,u%6};
    if(ret.se==0) {
        ret.fi--;
        ret.se +=6;
    }
    return ret;
}

void getAns(int u) {
    if(flag[u]) return;
    flag[u] = 1;
    dp[u].resize(u);
    if(u<=6) {
        ll temp = inv(u);
        rep(i,0,u) {
            dp[u][i] = temp;
        }
        return;
    }
    pii posu = getPos(u);
    int v1 = u - (posu.fi + 1);
    int v2 = u - (posu.fi);
    getAns(v1);
    if(posu.se<6) {
        getAns(v2);
    }
    rep(i,0,u) {
        dp[u][i] = 0;
        pii posi = getPos(i+1);
        rep(j,1,7) {
            if(j==posi.se) continue;
            int i2 = i - posi.fi;
            if(j<posi.se) {
                i2--;
            }
            int vv = (posu.se>=j?v1:v2);
            dp[u][i] = (dp[u][i] + iv6*dp[vv][i2]%mod)%mod;
            // cout <<u <<" " <<i <<"\n";
            // cout <<dp[u][i] <<"\n";
        }
    }
}

void solve() {
    cin >>n;
    getAns(n);
    rep(i,0,n) {
        cout <<dp[n][i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}