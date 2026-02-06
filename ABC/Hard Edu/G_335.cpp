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

const int mxn=2e5;
int n;
ll p, a[mxn];

ll fastexpo(ll x, ll e) {
    ll ret = 1;
    while(e) {
        if(e&1) {
            __int128_t retx = (__int128_t)(ret)*x%p;
            ret = retx;
        }
        __int128_t xx = (__int128_t)(x)*x%p;
        x = xx;
        e >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>p;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pri;
    ll u = p-1;
    vector<int> sp;
    int spi= 1;
    for(ll i=2;i*i<=u;i++) {
        if((u%i)==0) {
            // cout <<i <<"\n";
            pri.push_back(i);
            int ct = 0;
            while((u%i)==0) {
                u /=i;
                ct++;
            }
            sp.push_back(spi);
            spi *=(ct+1);
        }
    }
    if(u>1) {
        pri.push_back(u);
        sp.push_back(spi);
        spi *=2;
    }
    sp.push_back(spi);
    vector<int> sm(spi,0), ordS;
    vector<ll> ord(n,-1);
    rep(i,0,n) {
        ord[i] = p-1;
        rep(j,0,sz(pri)) {
            while((ord[i]%pri[j])==0) {
                ll ordi = ord[i]/pri[j];
                if(fastexpo(a[i],ordi)==1ll) {
                    ord[i] = ordi;
                } else {
                    break;
                }
            }
        }
        ll u2 = ord[i];
        int S=0;
        rep(j,0,sz(pri)) {
            while((u2%pri[j])==0) {
                S += sp[j];
                u2 /= pri[j];
            }
        }
        sm[S]++;
        ordS.push_back(S);
        // cout <<ord[i] <<" \n"[i==n-1];
        // cout <<ordS[i] <<" \n"[i==n-1];
    }
    rep(i,0,sz(pri)) {
        rep(S,0,sp[sz(pri)]) {
            int Sn = S + sp[i];
            int ak = (Sn%sp[i+1])/sp[i];
            if(ak) {
                sm[Sn] += sm[S];
            }
        }
    }
    ll ans = 0;
    rep(i,0,sz(ordS)) {
        ans += sm[ordS[i]];
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}