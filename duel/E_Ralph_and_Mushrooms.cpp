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

const int mxn=1e6;
int n,m,t;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g,f));

    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

ll vel(ll x) {
    ll l = 0, r= 2e4;
    ll bts = 0;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = mid*(mid+1)/2;
        if(cur<=x) {
            bts = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    } 
    ll ret = x*(bts+1) - (bts*(bts+1)/2 + bts*(bts+1)*(bts*2+1)/6)/2;
    // debug() <<imie(x) imie(bts) imie(ret);
    return ret;
}

void solve() {
    cin >>n >>m;
    vector<vi> g(n);
    vector<vector<pii>> gw(n);
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w; u--,v--;
        g[u].push_back(v);
        gw[u].push_back({w,v});
    }
    int s; cin >>s; s--;
    vector<ll> ans(n,0);
    scc(g, [&](vi& vc) {
        ll cur = 0;
        ll sm = 0;
        for(auto u: vc) {
            for(auto& [w,v]: gw[u]) {
                if(comp[v]<comp[u]) {
                    max_self(sm, ans[v] + w);
                } else {
                    cur += vel(w);
                }
            }
        }
        // cur /= 2;
        // debug() <<imie(cur);
        for(auto u: vc) {
            ans[u] = cur+sm;
            // debug() <<imie(u) imie(ans[u]);
        }
    });
    cout <<ans[s] <<"\n";
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