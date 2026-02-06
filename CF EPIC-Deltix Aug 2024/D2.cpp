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

const int mxn=3e5+1;
int n,q,t;
int a[mxn], p[mxn];

void solve() {
    cin >>n >>q;
    vector<vi> adj(n);
    rep(i,1,n) {
        cin >>a[i]; a[i]--;
        adj[a[i]].push_back(i);
    }
    rep(i,0,n) {
        cin >>p[i]; p[i]--;
    }
    vector<int> sub(n);
    function<void(int)> dfs;
    dfs = [&](int u) -> void {
        sub[u] = 1;
        for(int v: adj[u]) {
            dfs(v);
            sub[u] += sub[v];
        }
    };
    dfs(0);
    // debug() <<imie(sub);
    vector<pii> lr(n);
    vector<multiset<int>> ml(n),mr(n);
    rep(i,0,n) {
        int u = p[i];
        lr[u] = {i, i+sub[u]-1};
        if(u>0) {
            ml[a[u]].insert(lr[u].fi);
            mr[a[u]].insert(lr[u].se);
        }
    }
    int pr = 0;
    vector<bool> vpr(n,0);
    rep(i,0,n) {
        // debug() <<imie(ml[i]) imie(mr[i]);
        // debug() <<imie(lr[i]);
        if((sz(ml[i]) && (*ml[i].begin())<lr[i].fi) || (sz(mr[i]) && (*(--mr[i].end()))>lr[i].se)) {
            pr++;
            vpr[i] = 1;
        }
    }
    auto recalc = [&](int x) -> void {
        bool nw = sz(ml[x]) && ((*ml[x].begin())<lr[x].fi || (*(--mr[x].end()))>lr[x].se);
        if(nw!=vpr[x]) {
            if(nw) {
                pr++;
            } else {
                pr--;
            }
            vpr[x] = nw;
        }
    };
    // debug() <<imie(vpr);
    while(q--) {
        int x,y; cin >>x >>y; x--,y--;
        swap(p[x],p[y]);
        if(p[x]>0) {
            int par = a[p[x]];
            ml[par].erase(ml[par].find(lr[p[x]].fi));
            mr[par].erase(mr[par].find(lr[p[x]].se));
            ml[par].insert(x);
            mr[par].insert(x+sub[p[x]]-1);
            recalc(par);
        }
        lr[p[x]] = {x, x+sub[p[x]]-1};
        recalc(p[x]);
        if(p[y]>0) {
            int par = a[p[y]];
            ml[par].erase(ml[par].find(lr[p[y]].fi));
            mr[par].erase(mr[par].find(lr[p[y]].se));
            ml[par].insert(y);
            mr[par].insert(y+sub[p[y]]-1);
            recalc(par);
        }
        lr[p[y]] = {y, y+sub[p[y]]-1};
        recalc(p[y]);    
        // debug() <<imie(vpr);    
        if(pr==0) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
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