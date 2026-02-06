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

const int mxn=1e5,mxa=1e6;
const ll mod=1e9+7;
ll a,b,c,t;
vector<int> primes;
int fp[mxa+1];

ll fastexpo(ll base, ll exponent, ll md=mod) {
    ll ret =1;
    while(exponent) {
        if(exponent&1) {ret=(ret*base)%md;}
        base = (base*base)%md;
        exponent >>=1;
    }
    return ret;
}

void solve() {
    cin >>a >>b >>c;
    vector<int> num(sz(primes),0);
    ll k= min(c,b-c);
    per(i,b,b-k) {
        ll u = i;
        while(u>1) {
            num[fp[u]]++;
            u /=primes[fp[u]];
        }
    }
    per(i,k,0) {
        ll u = i;
        while(u>1) {
            num[fp[u]]--;
            u /=primes[fp[u]];
        }
    }
    ll bc = 1;
    rep(i,0,sz(primes)) {
        bc = bc*fastexpo(primes[i],num[i],mod-1)%(mod-1);
    }
    ll ans = fastexpo(a,bc);
    cout <<ans <<"\n";
}

void init() {
    vector<bool> isComposit(mxa+1,0);
    fill(fp,fp+mxa+1,1e9);
    rep(i,2,mxa+1) {
        if(!isComposit[i]) {
            for(int j=i*2;j<=mxa;j+=i) {
                min_self(fp[j],sz(primes));
                isComposit[j] = 1;
            }
            fp[i] = sz(primes);
            primes.push_back(i);
        }
    }
    // cout <<sz(primes) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}