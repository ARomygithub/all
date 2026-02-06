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

const int mxn=2e5;
const ll mod = 998244353;
int n,q,t;
int a[mxn],b[mxn];

ll fastexpo(ll ai, ll bi) {
    ll ret = 1;
    while(bi) {
        if(bi&1) ret = ret*ai%mod;
        ai = ai*ai%mod;
        bi >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    // auto naif = [&]() -> void {
        // vi va(a,a+n);
        // vi vb(b,b+n);
        // sort(all(va));
        // sort(all(vb));
    //     ll ans = 1;
    //     rep(i,0,n) {
    //         ans = ans*min(va[i],vb[i])%mod;
    //     }
    //     cout <<ans <<" ";
    // };
    vi a2(a,a+n);
    vi b2(b,b+n);
    sort(all(a2));
    sort(all(b2));    
    ll ans = 1;
    rep(i,0,n) {
        ans = ans*min(a2[i],b2[i])%mod;
    }
    multiset<pii> ma,mb;
    rep(i,0,n) {
        ma.insert({a2[i],b2[i]});
        mb.insert({b2[i],a2[i]});
    }
    vector<ll> vs;
    vs.push_back(ans);
    while(q--) {
        int qt; cin >>qt;
        int x; cin >>x; x--;
        if(qt==1) {
            auto it = ma.lower_bound({a[x]+1,-1});
            it--;
            auto [ax,bx] = *it;
            ma.erase(it);
            mb.erase(mb.find({bx,ax}));
            ans = ans*inv(min(ax,bx))%mod;
            ans = ans*min(ax+1,bx)%mod;
            ma.insert({ax+1,bx});
            mb.insert({bx,ax+1});
            a[x]++;
        } else {
            auto it = mb.lower_bound({b[x]+1,-1});
            it--;
            auto [bx,ax] = *it;
            mb.erase(it);
            ma.erase(ma.find({ax,bx}));
            ans = ans*inv(min(ax,bx))%mod;
            ans = ans*min(ax,bx+1)%mod;
            ma.insert({ax,bx+1});
            mb.insert({bx+1,ax});            
            b[x]++;
        }
        vs.push_back(ans);
    }
    rep(i,0,sz(vs)) {
        cout <<vs[i] <<" \n"[i==sz(vs)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}