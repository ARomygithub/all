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

const int mxn=50;
const ll mxa=1e9;
int n,t;
ll p,h;

void solve() {
    cin >>n >>p >>h;
    ll cta = 0;
    vector<ll> vm,va;
    rep(i,0,n) {
        char tp; cin >>tp;
        if(tp=='!') {
            cta++;
        } else if(tp=='*') {
            int x; cin >>x;
            vm.push_back(x);
        } else {
            int x; cin >>x;
            va.push_back(x);
        }
    }
    sort(all(vm),greater<ll>());
    sort(all(va),greater<ll>());
    if(cta==0 || (p==0 && sz(va)==0)) {
        cout <<"*\n";
        return;
    }
    rep(i,1,sz(vm)) {
        if(vm[i-1]>=mxa) {
            vm[i] = vm[i-1];
        } else {
            vm[i] = min(mxa, vm[i-1]*vm[i]);
        }
    }
    rep(i,1,sz(va)) {
        va[i] = min(mxa, va[i-1]+va[i]);
    }
    ll pn = p;
    if(sz(va)) {
        pn += va.back();
    }
    if(sz(vm)) {
        pn *= vm.back();
    }
    if(pn==p) {
        ll mx = p*cta;
        ll cround = (h-1)/mx;
        ll ans = cround*n;
        h -= cround*mx;
        ans += (h+p-1)/p;
        cout <<ans <<"\n";
        return;
    }
    min_self(pn, mxa);
    ll ans = 0;
    while(pn*cta < h) {
        ans += n;
        p = pn;
        h -= pn*cta;
        pn = p;
        if(sz(va)) {
            pn += va.back();
        }
        if(sz(vm)) {
            pn *= vm.back();
        }  
        min_self(pn, mxa);      
    }
    vector<ll> mx(n+1,0);
    rep(i,0,sz(va)+1) {
        rep(j,0,sz(vm)+1) {
            rep(k,1,cta+1) {
                ll cur = p;
                if(i>0) {
                    cur += va[i-1];
                }
                if(j>0) {
                    cur *= vm[j-1];
                }
                min_self(cur,mxa);
                max_self(mx[i+j+k], cur*k);
            }
        }
    }
    rep(i,1,n+1) {
        if(mx[i]>=h) {
            ans += i;
            break;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}