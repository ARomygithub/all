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

const int mxn=2e5;
const ll mod = 1e9+7;
int n,t;
ll a[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> ct(n,0);
    rep(i,0,n) {
        while((a[i]%2)==0) {
            ct[i]++;
            a[i] /= 2;
        }
    }
    vector<ll> ans(n,0);
    ll pr = 0;
    stack<int> st;
    auto isle = [&](int i, int j) -> bool {
        // debug() <<imie(i) <<imie(j);
        pll ai = {0, a[i]};
        pll aj = {ct[j], a[j]};
        // ai.fi -= min(ct[i],ct[j]);
        // aj.fi -= min(ct[i],ct[j]);
        // debug() <<imie(ai) imie(aj);
        if(aj.fi>=30) {
            return 1;
        }
        if(ai.fi>=30) {
            return 1;
        }
        return (1ll<<ai.fi)*ai.se < (1ll<<aj.fi)*aj.se;
    };
    rep(i,0,n) {
        pr = (pr + a[i])%mod;
        while(sz(st) && isle(st.top(),i)) {
            int id = st.top(); st.pop();
            ll cur = ((fastexpo(2,ct[id]) - 1 + mod)%mod)*a[id]%mod;
            pr = (pr - cur + mod)%mod;
            ct[i] += ct[id];
        }
        st.push(i);
        ll cur = (fastexpo(2,ct[i])-1+mod)%mod * a[i]%mod;
        pr = (pr + cur)%mod;
        ans[i] = pr;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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