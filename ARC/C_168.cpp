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

const int mxn=25e4,mxa=25e4;
const ll mod=998244353;
int n,k;
string s;
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

void solve() {
    cin >>n >>k;
    cin >>s;
    int sa=0,sb=0,sc=0;
    rep(i,0,n) {
        if(s[i]=='A') {
            sa++;
        } else if(s[i]=='B') {
            sb++;
        } else {
            sc++;
        }
    }
    ll ans = 0;
    rep(x,0,k+1) {
        rep(i,0,k+1) {
            rep(j,0,k+1) {
                rep(l,0,k+1) {
                    if(x*2+i+j+l > k) continue;
                    if(i+l+x>sa) continue;
                    if(i+j+x>sb) continue;
                    if(j+l+x>sc) continue;
                    ll temp = C(sa,i+x)*C(sa-i-x,l)%mod;
                    temp = temp*C(sb,j+x)%mod * C(sb-j-x,i)%mod;
                    temp = temp*C(sc,l+x)%mod * C(sc-l-x,j)%mod;
                    ans = (ans+temp)%mod;
                    if(x>0) {
                        temp = C(sa,l+x)*C(sa-l-x,i)%mod;
                        temp = temp*C(sb,i+x)%mod * C(sb-i-x,j)%mod;
                        temp = temp*C(sc,j+x)%mod * C(sc-j-x,l)%mod;
                        ans = (ans+temp)%mod;
                        // cout <<"tes" <<endl;
                        // cout <<temp <<endl;
                    }
                }
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_fac();
    solve();
}