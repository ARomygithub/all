#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const int mxn=1e5;
const ll mod = 998244353;
string x,y;

void solve() {
    cin >>x;
    cin >>y;
    vector<int> xl(sz(x),sz(x));
    xl[0] = 0;
    rep(i,1,sz(x)) {
        if(x[i]==x[i-1]) {
            xl[i] = i;
        } else {
            xl[i] = xl[i-1];
        }
    }
    vector ysub(26, vector<ll>(26,0));
    rep(i,0,sz(y)) {        
        rep(j,i,sz(y)) {
            if(j>i && y[j-1]==y[j]) {
                break;
            }
            ysub[y[i]-'a'][y[j]-'a']++;
        }
    }
    debug() <<imie(ysub);
    vector<ll> pre(26,0);
    rep(i,0,26) {
        rep(j,0,26) {
            rep(k,0,26) {
                if(k==i) continue;
                pre[i] = (pre[i]+ ysub[j][k])%mod;
            }
        }
    }
    vector ct(sz(x), vector<ll>(26,0));
    rep(i,0,sz(x)) {
        int cur = x[i]-'a';
        vector<ll>& ct_new = ct[i];
        rep(j,0,26) {
            rep(k,0,26) {
                if(k==cur) continue;
                ct_new[j] = (ct_new[j] + ysub[k][j]*(i-xl[i]+1)%mod)%mod;
            }
        }
        ct_new[cur] = (ct_new[cur] + pre[cur])%mod;
        rep(j,0,26) {
            rep(k,0,26) {
                if(j==cur) continue;
                ct_new[k] = (ct_new[k] + pre[cur]*ysub[j][k]%mod)%mod;
            }
        }
        if(i==0) continue;
        ll temp = 0;
        rep(j,0,26) {
            if(j==cur) continue;
            temp = (temp + ct[i-1][j])%mod;
        }
        ct_new[cur] = (ct_new[cur] + temp)%mod;
        rep(j,0,26) {
            rep(k,0,26) {
                if(j==cur) continue;
                ct_new[k] = (ct_new[k] + temp*ysub[j][k]%mod)%mod;
            }
        }
    }
    ll ans = 0;
    rep(i,0,sz(x)) {
        rep(j,0,26) {
            ans = (ans + ct[i][j])%mod;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}