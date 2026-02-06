#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sx(x) (int)x.size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int mxn = 1e2, mxa=5e7;
const ll mod = 1e9+7;
int n,m;
int a[mxn][mxn];
int fct[mxa+1],iv[mxa+1];

void init_fac() {
    iv[1] = 1;
    rep(i,2,mxa+1) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0] = 1, iv[0]=1;
    rep(i,1,mxa+1) {
        fct[i] = 1ll*fct[i-1]*i%mod;
        iv[i] = 1ll*iv[i-1]*iv[i]%mod;
    }
}

ll C(ll x, ll y) {
    if(x<y || x<0 || y<0) return 0;
    ll ret = 1ll*fct[x]*iv[y]%mod;
    ret = ret*iv[x-y]%mod;
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }
    rep(i,0,n) {
        rep(j,0,m) {
            if(j) {
                a[i][j] += a[i][j-1];
            } else {
                a[i][j] = 0;
            }
        }
        if(i) {
            rep(j,0,m) {
                a[i][j] += a[i-1][j];
                // cout <<a[i][j] <<" ";
            }
            // cout <<"\n";
        } else {
            rep(j,0,m) {
                a[i][j] = 0;
            }
        }
    }
    rep(i,0,n) {
        ll x = 0;
        rep(j,0,m) {
            x += a[i][j];
        }
        x /= m;
        ll y = x/2;
        cout <<C(x,y) <<"\n";
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    init_fac();
    solve();
}