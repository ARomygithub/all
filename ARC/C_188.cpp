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
int n,m;

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
    vector adj(n, vector(2,vi()));
    rep(i,0,m) {
        int a,b,c; cin >>a >>b >>c;a--,b--;
        adj[a][c].push_back(b);
    }
    UF uf(n*2);
    rep(i,0,n) {
        rep(k,0,2) {
            if(sz(adj[i][k])>1) {
                rep(j,0,sz(adj[i][k])-1) {
                    int u = adj[i][k][j], v = adj[i][k][j+1];
                    uf.join(u*2,v*2);
                    uf.join(u*2+1,v*2+1);
                }
            }
        }
        if(sz(adj[i][0])>0 && sz(adj[i][1])>0) {
            int u = adj[i][0][0], v = adj[i][1][0];
            uf.join(u*2,v*2+1);
            uf.join(u*2+1,v*2);
        }
    }
    set<int> st;
    rep(i,0,n) {
        st.insert(uf.find(i*2));
        st.insert(uf.find(i*2+1));
        if(uf.sameSet(i*2,i*2+1)) {
            cout <<"-1\n";
            return;
        }
    }
    set<int> lead;
    for(auto sti: st) {
        int lwn = sti^1;
        if(!lead.count(lwn)) {
            lead.insert(sti);
        }
    }
    // debug() <<imie(lead);
    string ans = "";
    rep(i,0,n) {
        bool conf = 0;
        int ia = uf.find(i*2), ib = uf.find(i*2+1);
        rep(j,0,sz(adj[i][0])) {
            int u = adj[i][0][j];
            int ua = uf.find(u*2), ub = uf.find(u*2+1);
            if((lead.count(ia) && lead.count(ub)) || (lead.count(ib) && lead.count(ua))) {
                conf = 1;
            }
            break;
        }
        rep(j,0,sz(adj[i][1])) {
            int u = adj[i][1][j];
            int ua = uf.find(u*2), ub = uf.find(u*2+1);
            if((lead.count(ia) && lead.count(ua)) || (lead.count(ib) && lead.count(ub))) {
                conf = 1;
            }
            break;
        }
        if(conf) {
            ans += '1';
        } else {
            ans += '0';
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