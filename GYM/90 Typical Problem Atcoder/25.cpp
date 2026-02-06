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

const int mxn=1e5,mxb=11;
ll n,b;

int ctdig(ll x) {
    int ret = 0;
    while(x) {
        ret++;
        x /= 10;
    }
    return ret;
}

void rec(ll& ret, vi& ct, int pos, int sisa) {
    auto tes = [&]() -> void {
        ll phi = 1;
        rep(i,1,10) {
            rep(j,0,ct[i]) {
                phi *= i;
            }
        }
        ll x = b + phi;
        bool ok = x<=n;
        vi ctx(10,0);
        while(x) {
            ctx[x%10]++;
            x /= 10;
        }
        rep(i,1,10) {
            ok = ok && (ct[i]==ctx[i]);
        }
        ok = ok && (ctx[0]==0);
        ret += ok;
    };
    if(sisa==0) {
        tes();
        return;
    }
    if(pos==9) {
        ct[pos] = sisa;
        tes();
        ct[pos] = 0;
        return;
    }
    rep(i,0,sisa+1) {
        ct[pos] = i;
        rec(ret, ct, pos+1,sisa-i);
        ct[pos] = 0;
    }
}

ll slv(int dig) {
    ll ret = 0;
    vi ct(10,0);
    rec(ret, ct, 1, dig);
    return ret;
}

void solve() {
    cin >>n >>b;
    int dig = ctdig(b);
    ll ans = 0;
    if(b<=n) {
        ll b2 = b;
        bool ada0 = 0;
        while(b2) {
            ada0 = ada0 || ((b2%10)==0);
            b2 /= 10;
        }
        ans += ada0;
    }
    rep(digi,dig,min(dig+2,12)) {
        ans += slv(digi);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}