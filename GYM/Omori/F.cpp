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

const int mxn=2e5;
int n,q;
int a[mxn],t[mxn], xr[mxn];
int s1 = 0;

void add(int ind, int end) { 
    s1 -= (xr[t[ind]-1]!=0);
    xr[t[ind]-1] ^= a[ind];
    s1 += (xr[t[ind]-1]!=0);
 } // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    s1 -= (xr[t[ind]-1]!=0);
    xr[t[ind]-1] ^= a[ind];
    s1 += (xr[t[ind]-1]!=0);    
 } // remove a[ind]
string calc() { 
    if(s1) {
        return "SUNNY";
    } else {
        return "BASIL";
    }
 } // compute current answer

vector<string> mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 447; // ~N/sqrt(Q)
	vector<int> s(sz(Q));
    vector<string> res(sz(Q));
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
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>t[i];
    }
    cin >>q;
    vector<pii> que(q);
    rep(i,0,q) {
        cin >>que[i].fi >>que[i].se; que[i].fi--;
    }
    auto ret = mo(que);
    rep(i,0,q) {
        cout <<ret[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}