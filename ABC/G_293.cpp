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
int n,qq;
int a[mxn+1];
int ct[mxn+1];
ll ans = 0;

ll f(ll x) {
    return x*(x-1)*(x-2)/6;
}

void add(int ind, int end) { 
    int now = ++ct[a[ind]];
    ans += f(now)-f(now-1);
 } // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    int now = --ct[a[ind]];
    ans += f(now)-f(now+1);
 } // remove a[ind]
ll calc() { return ans; } // compute current answer

vector<ll> mo(vector<pii> Q) {
    int L = 0, R = 0, blk = 447; // ~N/sqrt(Q)
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
    cin >>n >>qq;
    rep(i,1,n+1) {
        cin >>a[i];
    }
    vector<pii> que(qq);
    rep(i,0,qq) {
        cin >>que[i].fi >>que[i].se; que[i].se++;
    }
    auto ret = mo(que);
    rep(i,0,qq) {
        cout <<ret[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}