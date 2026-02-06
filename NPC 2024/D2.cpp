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

const int mxn=5e5;
int n;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

using tup = tuple<string, int , int>;
void solve() {
    cin >>n;
    vector<vi> adj;
    adj.push_back(vi());
    int id = 1;
    vector<ll> val(1,0);
    vector<bool> elim(1,0);
    vector upd(1, vector<pii>());
    rep(i,0,n) {
        string s; int t, x; cin >>s >>t;
        x = 0;
        if(s[0]=='S') {
            cin >>x;
            adj.push_back(vi());
            val.push_back(x);
            elim.push_back(0);
            upd.push_back(vector<pii>());
            adj[t].push_back(id);
            adj[id].push_back(t);
            id++;            
        } else if(s[sz(s)-1]=='k') {
            cin >>x;            
            upd[t].push_back({id-1,x});
        } else if(s[sz(s)-1]=='s') {
            elim[t] = 1;
        }        
        // debug() <<imie(s) imie(t) imie(x);
    }
    FT ft(id);
    // debug() <<imie(id);
    // debug() <<imie(val);
    vector<pll> ans;
    function<void(int,int)> dfs;
    dfs = [&](int u, int p) -> void {
        if(elim[u]) return;
        for(auto [bts, x]: upd[u]) {
            ft.update(bts, x);
        }
        ll add = ft.query(id) - ft.query(u);
        val[u] += add;
        ans.push_back({u,val[u]});
        for(int v: adj[u]) {
            if(v==p) continue;
            // val[v] += val[u];
            dfs(v,u);
        }
        for(auto [bts, x]: upd[u]) {
            ft.update(bts, -x);
        }
    };
    // debug() <<"tes";
    dfs(0,-1);
    sort(all(ans));
    rep(i,0,sz(ans)) {
        cout <<ans[i].se <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}