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

typedef pair<pll,bool> pllb;

const int mxn=1e6;
// const ll mxa = 4e18;
const ll mxa = 2e9;
ll n;
set<int> s;
vector<pllb> ans;

void doAdd(ll x, ll y) {
    // cout <<x <<" + " <<y <<"\n";
    ans.push_back({{x,y},false});
    s.insert(x+y);
}

void doXor(ll x, ll y) {
    // cout <<x <<" ^ " <<y <<"\n";
    ans.push_back({{x,y},true});
    s.insert(x^y);
}

void createMul(ll mul, ll a) {
    // cout <<"mul " <<mul <<" " <<a <<"\n";
    ll ret = 0;
    // if(!s.count(ret)) {
    //     doXor(n,n);
    // }
    ll p2 = a;
    while(mul) {
        if(mul&1) {
            if(!s.count(ret+p2)) {
                doAdd(ret, p2);
            }
            ret = ret+p2;
        }
        if(!s.count(p2*2)) {
            doAdd(p2, p2);
        }
        p2 *= 2ll;
        mul >>=1;
    }
}

void solve() {
    cin >>n;
    s.insert(n);
    ll one = -1;
    bool ok2 = 0;
    for(ll ni = n*2;ni< (n*75001) ; ni+=n) {
        ll md = (ni^n)%n;
        if(__gcd(md,n)==1) {
            ll mul = ni/n;
            createMul(mul, n);
            assert(ni<=mxa);
            one = ni^n;
            doXor(ni, n);
            ok2 = 1;
            break;
        }
    }
    assert(ok2);
    bool ok = 0;
    rep(i,1,n) {
        if(((one*i)%n)==1ll) {
            createMul(i, one);
            assert(mxa/one > i);
            one = one*i;
            ok = 1;
            break;
        }
    }
    assert(ok);
    // assert(one!=-1);
    // coba
    ll u = n, v = one;
    // cout <<u <<" " <<v <<endl;
    ll k2=v/n;
    // if(diff>0) {
        // add diff*n ke u createMul(k2, n)
    createMul(k2, n);
    u = k2*n;
    // }
    // case u odd, v even. add n to both
    if((u%2)) {
        if(!s.count(u+n)) {
            doAdd(u,n);
        }
        u += n;
        if(!s.count(v+n)) {
            doAdd(v,n);
        }
        v += n;
    }
    doXor(u,v);
    assert((u^v)==1);
    // assert(sz(ans)<=9);
    cout <<sz(ans) <<"\n";
    // rep(i,0,sz(ans)) {
    //     // if(ans[i].fi.se==10) continue;
    //     assert(ans[i].fi.fi <=mxa);
    //     assert(ans[i].fi.se <=mxa);
    //     cout <<ans[i].fi.fi <<(ans[i].se?" ^ ":" + ") <<ans[i].fi.se <<"\n";
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // assert(false);
    solve();
    // for(int i=118789;;i+=2) {
    //     s.clear();
    //     ans.clear();
    //     cout <<i <<endl;
    //     n = i;
    //     solve();
    // }
}