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

const int mxn=300;
const ll mod = 998244353;
int n;
ll iv[mxn+1],ifc[mxn+1];
using tup = tuple<int,int,int>;
vector<tup> cand;
map<tup,ll> dp;

void init() {
    iv[1] = 1;
    rep(i,2,mxn+1) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    ifc[0] = 1;
    rep(i,1,mxn+1) {
        ifc[i] = ifc[i-1]*iv[i]%mod;
    }
    rep(i,0,4) {
        rep(j,0,4) {
            rep(k,0,4) {
                if(i+j+k==3) {
                    cand.push_back({i,j,k});
                }
            }
        }
    }
}

ll C(ll a, ll b) {
    if(a<0 || a<b || b<0) return 0;
    if(b==0) return 1;
    if(b==1) return a;
    if(b==2) return (a*(a-1)/2)%mod;
    // b = 3
    ll ret = a*(a-1)%mod * (a-2)%mod;
    ret = ret*iv[6]%mod;
    return ret;
}

ll getDp(int ct1, int ct2, int ct3) {
    if(dp.count({ct1,ct2,ct3})) return dp[{ct1,ct2,ct3}];
    if(ct1==0 && ct2==0 && ct3==0) {
        dp[{ct1,ct2,ct3}] = 1;
        return 1;
    }
    dp[{ct1,ct2,ct3}] = 0;
    ll cur = 0;
    for(auto [a,b,c] : cand) {
        if(ct1>=a && ct2>=b && ct3>=c) {
            ll tmp = getDp(ct1-a+b,ct2-b+c,ct3-c)*C(ct1,a)%mod*C(ct2,b)%mod * C(ct3,c)%mod;
            rep(i,0,b) {
                tmp = tmp*2%mod;
            }
            rep(i,0,c) {
                tmp = tmp*3%mod;
            }
            cur = (cur + tmp)%mod;
        }
    }
    dp[{ct1,ct2,ct3}] = cur;
    return cur;
}

void solve() {
    cin >>n;
    int k = n/3;
    ll ans = getDp(0,0,k)*ifc[k]%mod; 
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    // rep(i,1,41) {
    //     n = i*3;
    //     solve();
    // }
    solve();
}