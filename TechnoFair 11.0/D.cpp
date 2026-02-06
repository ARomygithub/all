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
ll n;
set<int> s;
vector<ll> dp, last;
pii coba;
bool globalOk=0;
vector<pllb> ans;

void doAdd(ll x, ll y) {
    // cout <<x <<" + " <<y <<"\n";
    ans.push_back({{x,y},false});
    s.insert(x+y);
    ll temp = (x+y)%n;
    if(dp[(x+y)%n]==-1) {
        dp[temp] = x+y;
        if(dp[(temp-1+n)%n]>-1) {
            coba = {(temp-1+n)%n, temp};
            globalOk = 1;
        }
        if(dp[(temp+1)%n]>-1) {
            coba = {temp,(temp+1)%n};
            globalOk = 1;
        }
    }
    max_self(last[temp], x+y);
}

void doXor(ll x, ll y) {
    // cout <<x <<" ^ " <<y <<"\n";
    ans.push_back({{x,y},true});
    s.insert(x^y);
    ll temp = (x^y)%n;
    if(dp[temp]==-1) {
        dp[temp] = x^y;
        ll prv = (temp-1+n)%n;
        ll nxt = (temp+1)%n;
        if(dp[prv]>-1) {
            coba = {prv, temp};
            globalOk = 1;
        }
        if(dp[nxt]>-1) {
            coba = {temp, nxt};
            globalOk = 1;
        }
    }
    max_self(last[temp], x^y);
}

void solve() {
    cin >>n;
    dp.resize(n, -1);
    last.resize(n, -1);
    dp[0] = n;
    s.insert(n);
    doAdd(n, n);
    ll nn = (n*2)^n;
    // cout <<nn <<endl;
    queue<int> q; 
    if(!s.count(nn)) {
        doXor(n*2, n);
        q.push(nn%n);
    }
    while(sz(q) && !globalOk) {
        int u = q.front(); q.pop();
        ll mul = 1;
        // int ct = 0;
        while(true && !globalOk) {
            // cout <<dp[u] <<" " <<u <<endl;
            // ct++;
            ll temp = (mul*dp[0])^dp[u];
            if(dp[temp%n]==-1) {
                while(last[0]<mul*dp[0]) {
                    doAdd(last[0], dp[0]);
                    last[0] += dp[0];
                }
                doXor(mul*dp[0], dp[u]);
                q.push(temp%n);
                break;
            }
            ll mul2 = (mul*dp[u]+dp[0]-1)/dp[0];
            temp = (mul2*dp[0])^(mul*dp[u]);
            if(dp[temp%n]==-1) {
                while(last[0]<mul2*dp[0]) {
                    doAdd(last[0], dp[0]);
                    last[0] += dp[0];
                }                
                while(last[u]<mul*dp[u]) {
                    doAdd(last[u], dp[u]);
                    last[u] += dp[u];
                }
                doXor(mul*dp[u], mul2*dp[0]);
                q.push(temp%n);
                break;
            }
            mul++;
        }
        // if(ct==50) {

        // }
    }
    // coba
    ll u = dp[coba.fi], v = dp[coba.se];
    // cout <<u <<" " <<v <<endl;
    ll p = coba.se;
    ll k1 = u/n, k2=v/n;
    ll diff = k2-k1;
    if(p==0ll) {
        diff--;
    }
    if(diff<0) {
        // add diff*n ke v
        // cout <<"tes" <<endl;
        ll mul = 0;
        if(!s.count(0)) {
            doXor(n,n);
        }
        ll temp = diff*(-1);
        ll a = n;
        while(temp) {
            // cout <<"tes" <<endl;
            if(temp&1) {
                if(!s.count(mul+a)) {
                    doAdd(mul, a);
                }
                mul += a;
            } 
            if(!s.count(a+a)) {
                doAdd(a,a);
            }
            a = a*2;
            temp >>=1;
        }
        if(!s.count(v+mul)) {
            doAdd(v, mul);
        }
        v += mul;
    } else if(diff>0) {
        // add diff*n ke u
        ll mul = 0;
        if(!s.count(0)) {
            doXor(n,n);
        }
        ll temp = diff;
        ll a = n;
        while(temp) {
            if(temp&1) {
                if(!s.count(mul+a)) {
                    doAdd(mul, a);
                }
                mul += a;
            } 
            if(!s.count(a+a)) {
                doAdd(a,a);
            }
            a = a*2;
            temp >>=1;
        }
        if(!s.count(u+mul)) {
            doAdd(u, mul);
        }        
        u += mul;
    }
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
    cout <<sz(ans) <<"\n";
    // assert(sz(ans)<=100000);
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi.fi <<(ans[i].se?" ^ ":" + ") <<ans[i].fi.se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    // for(int i=118789;;i+=2) {
    //     globalOk = 0;
    //     s.clear();
    //     cout <<i <<endl;
    //     n = i;
    //     solve();
    // }
}