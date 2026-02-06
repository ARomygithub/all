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

const int mxn=200,mxa=200;
const ll mod = 1e9+7;
int n,m;
ll dp[mxn+1][mxn+1][mxn+1];
bool vis[mxn+1][mxn+1][mxn+1];
ll fct[mxa+1],ifc[mxa+1],iv[mxa+1];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}

ll getdp(int ct1, int ct2, int ct3) {
    if(vis[ct1][ct2][ct3]) return dp[ct1][ct2][ct3];
    if(ct1==0 && ct2==0 && ct3==0) return 1;
    vis[ct1][ct2][ct3] = 1;
    rep(i,0,4) {
        rep(j,0,4-i) {
            int k = 3-i-j;
            if(ct1>=i && ct2>=j && ct3>=k) {
                ll cur = getdp(ct1-i+j,ct2-j+k,ct3-k);
                cur = cur*C(ct1,i)%mod;
                cur = cur*C(ct2,j)%mod;
                cur = cur*fastexpo(2,j)%mod;
                cur = cur*C(ct3,k)%mod;
                cur = cur*fastexpo(3,k)%mod;
                dp[ct1][ct2][ct3] = (dp[ct1][ct2][ct3] + cur)%mod;
            }
        }
    } 
    return dp[ct1][ct2][ct3];
}

void solve() {
    cin >>n >>m;
    int k = n/3;
    set<int> udh;
    rep(i,0,m) {
        rep(j,0,3) {
            int x; cin >>x; x--;
            udh.insert(x);
        }
    }
    vi st(3,0);
    for(int i=0;i<n;i+=3) {
        int ct = 0;
        rep(j,0,3) {
            ct += !(udh.count(i+j));
        }
        if(ct>0) {
            st[ct-1]++;
        }
    }
    // cout <<st[0] <<" " <<st[1] <<" " <<st[2] <<endl;
    cout <<getdp(st[0],st[1],st[2])*ifc[k-m]%mod <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}