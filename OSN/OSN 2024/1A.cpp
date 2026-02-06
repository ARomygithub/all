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
using pil = pair<int,ll>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,w[mxn],d[mxn];
vi adj[mxn];
int sub[mxn];
ll ans[mxn][2][2];

void dfs1(int u, int p=-1) {
    sub[u] = 1;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs1(v,u);
        sub[u] += sub[v];
    }
}

void dfs2(int u, int p=-1) {
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs2(v,u);
    }
    rep(i,0,2) {
        rep(j,0,2) {
            ans[u][i][j] = i>0?w[u]:-w[u];
            multiset<ll> s;
            for(int v: adj[u]) {
                if(v==p) continue;
                int i2 = 1-i;
                ans[u][i][j] += ans[v][i][j];
                s.insert(ans[v][i2][j]-ans[v][i][j]);
            }
            if(!sz(s)) continue;
            if(j==0) {
                auto it = s.begin();
                rep(k,0,d[u]) {
                    ans[u][i][j] += *it;
                    it++;
                }
            } else {
                auto it = --s.end();
                rep(k,0,d[u]) {
                    ans[u][i][j] += *it;
                    it--;
                }
            }
        }
    }
}

void solve() {
    cin >>n;
    rep(i,1,n) {
        int u; cin >>u; u--;
        adj[u].push_back(i);
    }
    rep(i,0,n) {
        cin >>w[i];
    }
    rep(i,0,n) {
        cin >>d[i];
    }
    dfs1(0,-1);
    dfs2(0,-1);
    ll ansi = 0;
    rep(i,0,2) {
        rep(j,0,2) {
            max_self(ansi, abs(ans[0][i][j]));
        }
    }
    cout <<ansi <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}