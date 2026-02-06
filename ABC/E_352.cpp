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

const int mxn=2e5;
int n,m;
vector<int> s[mxn];
int c[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int ki; cin >>ki >>c[i];
        s[i].resize(ki);
        rep(j,0,ki) {
            cin >>s[i][j]; s[i][j]--;
        }
    }
    vector<pii> pos;
    rep(i,0,m) {
        pos.push_back({c[i],i});
    }
    sort(pos.begin(),pos.end());
    ll ans = 0;
    UF uf(n);
    rep(i,0,m) {
        int cur = pos[i].se;
        rep(j,0,sz(s[cur])-1) {
            if(uf.join(s[cur][j], s[cur][j+1])) {
                ans += c[cur];
            }
        }
    }
    if(uf.size(0)==n) {
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}