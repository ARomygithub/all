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
int n;
int s[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector gr(n+1, vector<int>());
    rep(i,0,n-1) {
        int u,v; cin >>u >>v;
        // gr[s[u-1]].push_back(s[v-1]);
        // gr[s[v-1]].push_back(s[u-1]);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    // https://vjudge.net/problem/SPOJ-LISTREE
    vi val(n+1, 0);
    vi mx(n+1, 0);
    vi dep(n+1, -1);
    vi heavyChild(n+1, -1);

    function<int(int)> dfsHeavy;
    dfsHeavy = [&](int node) -> int {
        int szi = 1, mx = 0;
        for(auto& next: gr[node]) {
            if(dep[next]!=-1) continue;
            dep[next] = dep[node] + 1;
            int sc = dfsHeavy(next);
            if(sc > mx) {
                mx = sc;
                heavyChild[node] = next;
            }
            szi += sc;
        }
        return szi;
    };
    dep[1] = 0;
    dfsHeavy(1);

    class FT {
        private:
            int cnt, n;
            vi BIT;
            vector<tuple<int,int,int>> hist;
        public:
            FT(int _n): n(_n), cnt(0) {
                BIT.resize(n+1);
            }
            inline void update(int idx, int val) {
                for(int i=idx;i<=n;i+= i&-i) {
                    hist.push_back({i, BIT[i], cnt});
                    BIT[i] = max(BIT[i], val);
                }
                ++cnt;
            }
            inline int query(int idx) {
                int res = 0;
                for(int i= idx; i; i-= i&-i) {
                    max_self(res, BIT[i]);
                }
                return res;
            }
            inline bool rollback() {
                if(hist.empty()) return false;
                int id = get<2>(hist.back());
                for(; !hist.empty() && get<2>(hist.back()) == id; hist.pop_back()) {
                    BIT[get<0>(hist.back())] = get<1>(hist.back());
                }
                return true;
            }
            inline void reset() {
                for(; rollback(); );
            }
    };
    FT bit(mxn);
    int ans = 0;

    function<void(int)> trySubtree;
    trySubtree = [&](int node) -> void {
        int tmp = bit.query(val[node] - 1) + 1;
        bit.update(val[node], tmp);
        max_self(ans, tmp);
        for(auto& next: gr[node]) {
            if(dep[next] <= dep[node]) continue;
            trySubtree(next);
        }
        bit.rollback();
    };
    function<void(int)> addSubtree;
    addSubtree = [&](int node) -> void {
        bit.update(val[node], mx[node]);
        for(auto& next: gr[node]) {
            if(dep[next] <= dep[node]) continue;
            addSubtree(next);
        }
    };

    function<void(int,bool)> slv;
    slv = [&](int node, bool needReset) -> void {
        // debug() <<imie(node) imie(needReset);
        for(auto &next: gr[node]) {
            if(dep[next] <= dep[node] || next == heavyChild[node]) continue;
            slv(next, true);
        }
        if(heavyChild[node]!=-1) slv(heavyChild[node], false);
        mx[node] = bit.query(val[node]-1) + 1;
        max_self(ans, mx[node]);
        bit.update(val[node], mx[node]);
        for(auto &next: gr[node]) {
            if(dep[next] <= dep[node] || next == heavyChild[node]) continue;
            trySubtree(next);
            addSubtree(next);
            mx[node] = bit.query(val[node] - 1) + 1;
            max_self(ans, mx[node]);
            bit.update(val[node], mx[node]);
        }

        if(needReset) bit.reset();
    };

    rep(i,1,n+1) val[i] = s[i-1];
    slv(1, true);
    mx.resize(n+1, 0);
    rep(i,1,n+1) val[i] = mxn+1-s[i-1]; // ini ganti?
    slv(1, true);

    cout <<ans <<"\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}