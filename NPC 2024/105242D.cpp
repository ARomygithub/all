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

const int mxn=1e5,mxp=16;
int t;
ll ad[mxn+1][mxp+1], ans[mxn+1];

void solve() {
    int n; cin >>n;
    cout <<ans[n] <<"\n";
}

void prec() {
    ans[1] = 1;
    map<int,int> mp;
    rep(i,2,mxn+1) {
        vector<pii> vp;
        int u = i;
        for(ll j = 2; j*j<=u;j++) {
            if((u%j)==0) {
                int vpi = 0;
                while((u%j)==0) {
                    vpi++;
                    u /= j;
                }
                vp.push_back({j,vpi});
            }
        }
        if(u>1) {
            vp.push_back({u,1});
        }
        int d = 0;
        rep(j,0,sz(vp)) {
            d = __gcd(d,vp[j].se);
        }
        int d2 = 0;
        while((d%2)==0) {
            d2++;
            d /= 2;
        }
        u = 1;
        rep(j,0,sz(vp)) {
            rep(k,0,vp[j].se/(1<<d2)) {
                u *= vp[j].fi;
            }
        }
        ans[i] = ans[i-1] + sz(mp);
        if(!mp.count(u)) {
            mp[u] = d2+1;
            ans[i] += d2+i;
        } else if(d2+1> mp[u]) {
            ans[i] += (d2+1)-mp[u];
            mp[u] = d2+1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prec();
    // rep(i,1,mxn+1) {
    //     cout <<i <<": " <<ans[i] <<"\n";
    // }
    cin >>t;
    while(t--) {
        solve();
    }
}