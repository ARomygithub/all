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
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

void solve() {
    string s;
    cin >>s;
    int q; cin >>q;
    vector<int> ans(q,0);
    vector<string> qry(q);
    vector<pii> v;
    HashInterval hs(s);
    rep(i,0,q) {
        cin >>qry[i];
        v.push_back({sz(qry[i]), i});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<q;) {
        int j = i;
        while(j<q && v[j].fi==v[i].fi) {
            j++;
        }
        map<ull,int> mp;
        rep(k,0,sz(s)-v[i].fi+1) {
            mp[hs.hashInterval(k,k+v[i].fi).get()]++;
        }
        rep(k,i,j) {
            ans[v[k].se] = mp[hashString(qry[v[k].se]).get()];
        }
        i = j;
    }
    rep(i,0,q) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}