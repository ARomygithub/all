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
#define all(x) begin(x), end(x)

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e4,mxa=1e6;
int n,q;
int a[mxn+1],ans=0;
int ct[mxa+1];

void add(int ind, int end) { 
    ct[a[ind]]++;
    if(ct[a[ind]]==1) {
        ans++;
    }
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    ct[a[ind]]--;
    if(ct[a[ind]]==0) {
        ans--;
    }
 } // remove a[ind]
int calc() { return ans; } // compute current answer

vi mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
	vi s(sz(Q)), res = s;
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
    cin >>n;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    cin >>q;
    vector<pii> vq(q);
    rep(i,0,q) {
        cin >>vq[i].fi >>vq[i].se;
        vq[i].se++;
    }
    vi res = mo(vq);
    rep(i,0,q) {
        cout <<res[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}