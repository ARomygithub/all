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
ll n;
bool vis[63][30];
ll dp[63][30];

ll C(int posbit, int bit) {
    if(vis[posbit][bit]) return dp[posbit][bit];
    dp[posbit][bit] = 1;
    vector<ll> ats,bwh;
    rep(i,0,bit) {
        bwh.push_back(bit-i);
        ats.push_back(posbit-i);
    }
    rep(i,0,sz(bwh)) {
        int j = 0;
        while(bwh[i]!=1) {
            ll d = __gcd(bwh[i],ats[j]);
            bwh[i] /=d;
            ats[j] /=d;
            j++;
        }
    }
    rep(i,0,sz(ats)) {
        dp[posbit][bit] *=ats[i];
    }
    return dp[posbit][bit];
}

void solve() {
    cin >>n;
    vector<ll> pos(30);
    iota(pos.begin(),pos.end(),0);
    per(bit,29,-1) {
        ll ct = C(pos[bit],bit);
        while(ct<n) {
            n -= ct;
            pos[bit]++;
            ct = C(pos[bit],bit);
        }
    }
    ll ans = 0;
    rep(bit,0,30) {
        ans += (1ll<<pos[bit]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}