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
int n,k;
// max matching

void solve() {
    cin >>n >>k;
    set<pii> s;
    rep(i,0,k) {
        int x,y; cin >>x >>y; x--,y--;
        if(x>y) swap(x,y);
        s.insert({x,y});
    }
    vector adj(n, set<int>());
    for(auto [x,y]: s) {
        adj[x].insert(y);
        adj[y].insert(x);
    }
    set<pii> sct;
    int mx = 0;
    rep(i,0,n) {
        sct.insert({sz(adj[i]),i});
    }
    auto er = [&](int i) -> void {
        for(auto v: adj[i]) {
            sct.erase({sz(adj[v]),v});
            adj[v].erase(i);
            if(sz(adj[v])) {
                sct.insert({sz(adj[v]),v});
            }
        }
        sct.erase({sz(adj[i]),i});
        adj[i].clear();
    };
    while(sz(sct)) {
        auto [szi, i] = *sct.begin();
        debug() <<imie(szi) imie(i);
        if(szi) {
            int y = -1, ct = 1e9;
            for(auto v: adj[i]) {
                if(sz(adj[v])<ct) {
                    ct = sz(adj[v]);
                    y = v;
                }
            }
            debug() <<imie(y);
            mx++;
            er(y);
        }
        er(i);
    }
    cout <<k-mx <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}