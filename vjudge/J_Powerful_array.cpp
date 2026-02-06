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

const int mxn=2e5,mxa=1e6;
int n,q;
ll ans = 0;
int ct[mxa+1];
int a[mxn];

void add(int ind, int end) { 
    ans += 1ll*(ct[a[ind]]*2+1)*a[ind];
    ct[a[ind]]++;
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    ct[a[ind]]--;
    ans -= 1ll*(ct[a[ind]]*2+1)*a[ind];
} // remove a[ind]
ll calc() { return ans; } // compute current answer

vector<ll> mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 450; // ~N/sqrt(Q)
	vi s(sz(Q));
    vector<ll> res(sz(Q));
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) {
		pii q = Q[qi];
		while (L > q.first) add(--L, 0);
		while (R < q.second) add(R++, 1);
		while (L < q.first) del(L++, 0);
		while (R > q.second) del(--R, 1);
		res[qi] = calc();
	}
	return res;
}

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> qry(q);
    rep(i,0,q) {
        cin >>qry[i].fi >>qry[i].se;
        qry[i].fi--;
    }
    auto ans = mo(qry);
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