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

const int mxn=3e6;
int n,t;
vi adj[mxn];
string s[mxn];
int sn[mxn], a[mxn], d[mxn];
set<pii> st[mxn],st0;
map<int,int> mp[mxn],mp0;

void mrg(int u, int v) {
    if(sz(st[u])<sz(st[v])) {
        st[u].swap(st[v]);
        mp[u].swap(mp[v]);
    }
    for(auto& [ct,id]: st[v]) {
        if(mp[u].count(id)) {
            st[u].erase({mp[u][id], id});
            mp[u][id] += ct;
            st[u].insert({mp[u][id], id});
        } else {
            mp[u][id] = ct;
            st[u].insert({ct, id});
        }
    }
    st[v].clear();
    mp[v].clear();
}

void dfs(int u) {
    if(sz(st0)) {
        auto [ct, id] = *st0.begin();
        a[u] = id;
    }
    if(mp0.count(sn[u])) {
        st0.erase({mp0[sn[u]],sn[u]});
        mp0[sn[u]]++;
        st0.insert({mp0[sn[u]],sn[u]});
    } else {
        mp0[sn[u]] = 1;
        st0.insert({1,sn[u]});
    }
    for(int v: adj[u]) {
        dfs(v);
    }
    if(mp0[sn[u]]==1) {
        mp0.erase(sn[u]);
        st0.erase({1,sn[u]});
    } else {
        st0.erase({mp0[sn[u]],sn[u]});
        mp0[sn[u]]--;
        st0.insert({mp0[sn[u]],sn[u]});
    }
    for(int v: adj[u]) {
        mrg(u, v);
    }
    if(sz(st[u])) {
        auto [ct, id] = *st[u].begin();
        d[u] = id;
    }
    if(mp[u].count(sn[u])) {
        st[u].erase({mp[u][sn[u]], sn[u]});
        mp[u][sn[u]]++;
        st[u].insert({mp[u][sn[u]], sn[u]});
    } else {
        mp[u][sn[u]] = 1;
        st[u].insert({1,sn[u]});
    }
}
const ll mod = 998244353;

void solve() {
    cin >>n;
    rep(i,0,n) {
        int p; cin >>p >>s[i];
        if(p!=-1) {
            p--;
            adj[p].push_back(i);
        }
    }
    set<string> sts;
    rep(i,0,n) {
        sts.insert(s[i]);
    }
    map<string,int> mps;
    int idi = 1;
    for(auto& stsi : sts) {
        mps[stsi] = idi++;
    }
    rep(i,0,n) {
        sn[i] = mps[s[i]];
    }
    dfs(0);
    ll u = idi-1;
    ll hs = 0;
    rep(i,0,n) {
        hs = hs*(u+1) + a[i];
        hs %= mod;
        hs = hs*(u+1) + d[i];
        hs %= mod;
        // debug() <<imie(i) imie(a[i]) imie(d[i]);
    }
    cout <<hs <<"\n";
    rep(i,0,n) {
        adj[i].clear();
        sn[i] = 0;
        a[i] = 0;
        d[i] = 0;
        st[i].clear();
        mp[i].clear();
    }
    st0.clear();
    mp0.clear();
}

void main_() {
    // implement your solution here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }    
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}