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

const int mxn=3e5;
int n,t;
vi adj[mxn];
int d[mxn], l1[mxn],l2[mxn];
int mx2 = 0;
// string s;

bool dfs(int u, int p) {
    // debug() <<imie(u) imie(p) imie(mx);
    bool ret = 1;
    max_self(mx2, d[u]);
    l1[u] = d[u];
    // debug() <<imie(u) imie(d[u]);
    for(int v: adj[u]) {
        if(v==p) continue;
        ret = ret && (u<v);
        // if(!ret) return ret;
        d[v] = d[u]+1;
        ret = dfs(v,u) && ret;
        if(l1[v]>l2[u]) {
            l2[u] = l1[v];
        }
        if(l2[u]>l1[u]) {
            swap(l2[u],l1[u]);
        }
        // if(!ret) return ret;
    }
    // debug() <<imie(u) imie(l1[u]) imie(l2[u]);
    max_self(mx2, l1[u]+l2[u]-d[u]*2);
    return ret;
}

void solve() {
    // cin >>s;
    cin >>n;
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = dfs(0,-1);
    // debug() <<imie(ok) imie(mx2);
    // if(s[0]=='k') {
    //     cout <<"Lucky\n";
    // } else if(s[2]=='k') {
    //     if(mx2<=2) {
    //         cout <<"Lucky\n";
    //     } else {
    //         cout <<"Wrong\n";
    //     }
    // } else {
    if(ok || mx2<=2) {
        cout <<"Lucky\n";
    } else {
        cout <<"Wrong\n";
    }
    // }
    rep(i,0,n) {
        adj[i].clear();
        d[i] = 0;
        l1[i] = 0, l2[i]=0;
    }
    mx2 = 0;
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