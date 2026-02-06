#include <bits/stdc++.h>
using namespace std;

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

const int mxn=22;
int n,t;
string s;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}
const ll mod = 998244353;

void solve() {
    cin >>n;
    cin >>s;
    map<ull,int> mp;
    int id = 0;
    vi v((1<<n));
    rep(bit,0,(1<<n)) {
        string si = "";
        rep(j,0,n) {
            if((bit>>j)&1) {
                si += s[j];
            }
        }
        ull hsu = hashString(si).get();
        if(!mp.count(hsu)) {
            mp[hsu] = id;
            id++;
        }
        v[bit] = mp[hsu];
    }
    // cout <<id <<"\n";
    vector adj(id, vi());
    rep(bit,0,(1<<n)) {
        rep(j,0,n) {
            if(!((bit>>j)&1)) {
                int bitn = bit | (1<<j);
                adj[v[bit]].push_back(v[bitn]);
            }
        }
    }
    rep(i,0,id) {
        sort(all(adj[i]));
        auto ip = unique(all(adj[i]));
        adj[i].resize(distance(adj[i].begin(),ip));
    }
    queue<int> q;
    vector<ll> ct(id,0);
    vector<bool> udh(id,0);
    ct[0] = 1;
    q.push(0);
    udh[0] = 1;
    while(sz(q)) {
        auto u = q.front(); q.pop();
        for(int v: adj[u]) {
            ct[v] = (ct[v] + ct[u])%mod;
            if(!udh[v]) {
                q.push(v);
                udh[v] = 1;
            }
        }
    }
    cout <<ct[id-1] <<"\n";
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