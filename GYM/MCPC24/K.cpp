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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=51;
ll n,m,k;
ll a[mxn];

vector<ll> rec(ll ni, ll mi) {
    if(ni>mi) swap(ni,mi);
    if(ni==0) {
        return vector<ll>(mxn,0);
    }
    ll b2 = 0;
    while((1ll<<(b2+1)) <= ni) {
        b2++;
    }
    vector<ll> ret = rec(ni-(1ll<<b2), (1ll<<b2));
    ret[b2]++;
    rep(i,0,mxn) {
        ret[i] *= mi/(1ll<<b2);
    }
    auto ret2 = rec(ni, mi%(1ll<<b2));
    rep(i,0,mxn) {
        ret[i] += ret2[i];
    }
    return ret;
}

void solve() {
    cin >>n >>m >>k;
    rep(i,0,k) {
        cin >>a[i];
    }
    auto ret = rec(n,m);
    // debug() <<imie(ret);
    ll ans = 0;
    per(i,mxn-1,-1) {
        ll tmp = min(ret[i],a[i]);
        ans += tmp;
        ret[i] -= tmp;
        if(i) {
            ret[i-1] += ret[i]*4;
            if(ret[i-1]>(1ll<<mxn)) {
                cout <<"-1\n";
                return;
            }
        }
    }
    if(ret[0]>0) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}