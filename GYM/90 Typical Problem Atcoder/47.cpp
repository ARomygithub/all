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

const int mxn=1e5;
int n;
string s,t;

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

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(vi& str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

void solve() {
    cin >>n;
    cin >>s;
    cin >>t;
    vector vs(3, vi());
    map<char,int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    rep(i,0,n) {
        vs[mp[s[i]]].push_back(i);
    }
    vector vt(3, vi());
    rep(i,0,n) {
        vt[mp[t[i]]].push_back(i);
    }
    rep(i,0,3) {
        per(j,sz(vs[i])-1,0) {
            vs[i][j] -= vs[i][j-1];
        }
    }
    rep(i,0,3) {
        per(j,sz(vt[i])-1,0) {
            vt[i][j] -= vt[i][j-1];
        }
    }    
    vector<HashInterval> vhs;
    rep(i,0,3) {
        vhs.push_back(HashInterval(vs[i]));
    }
    vector<HashInterval> vht;
    rep(i,0,3) {
        vht.push_back(HashInterval(vt[i]));
    }
    vector sl(n, vector<pii>(3,{0,0})), sr(n, vector<pii>(3,{0,0}));
    vector tl(n, vector<pii>(3,{0,0})), tr(n, vector<pii>(3,{0,0}));
    rep(i,0,n) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}