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

const int mxn=1e5;
int n,m,t;
using tup = tuple<int,int,int>;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve() {
    cin >>n >>m;
    vector adj(n, set<int>());
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<tup> ans;
    rep(i,0,n) {
        while(true) {
            auto it = adj[i].lower_bound(i);
            if(it==adj[i].end()) break;
            auto nx = it; nx++;
            if(nx==adj[i].end()) break;
            int vit = *it, vnx = *nx;
            ans.push_back({i,*it,*nx});
            adj[i].erase(vit);
            adj[vit].erase(i);
            adj[i].erase(vnx);
            adj[vnx].erase(i);
            if(adj[vit].count(vnx)) {
                adj[vit].erase(vnx);
                adj[vnx].erase(vit);
            } else {
                adj[vit].insert(vnx);
                adj[vnx].insert(vit);
            }
        }
    }
    UF uf(n);
    int ct = 0;
    rep(i,0,n) {
        for(auto v: adj[i]) {
            if(uf.join(i,v)) {
                ct++;
            }
        }
    }
    auto dn = [&]() -> void {
        cout <<sz(ans) <<"\n";
        rep(i,0,sz(ans)) {
            auto [a,b,c] = ans[i];
            cout <<a+1 <<" " <<b+1 <<" " <<c+1 <<"\n";
        }
    };
    if(ct==0) {
        dn();
        return;
    }
    set<int> cand;
    pii rt = {-1,-1};
    rep(i,0,n) {
        int pr = uf.find(i);
        cand.insert(pr);
        if(rt.fi==-1 && sz(adj[pr])>0) {
            rt = {pr, (*adj[pr].begin())};
        }
    }
    // debug() <<imie(cand);
    for(auto candi: cand) {
        if(candi==rt.fi) continue;
        ans.push_back({rt.fi,rt.se,candi});
        rt.se = candi;
    }
    dn();
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