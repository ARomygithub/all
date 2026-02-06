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

const int mxn=3e5;
int n,m,a[mxn];
int mp[mxn+1];
int ct = 0;

void add(int ind, int end) { 
    mp[a[ind]]++;
    if(mp[a[ind]]==1) {
        ct++;
    }
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) { 
    mp[a[ind]]--;
    if(mp[a[ind]]==0) {
        ct--;
    }
} // remove a[ind]
int calc() { 
    return ct;
} // compute current answer

ll mo(vector<pii> Q) {
    int L = 0, R = 0, blk = 530; // ~N/sqrt(Q)
    vi s(sz(Q));
    ll res = 0;
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
    iota(all(s), 0);
    sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
    for (int qi : s) {
        pii q = Q[qi];
        while (L > q.first) add(--L, 0);
        while (R < q.second) add(R++, 1);
        while (L < q.first) del(L++, 0);
        while (R > q.second) del(--R, 1);
        res += calc();
    }
    return res;
}

void solve() {
    cin >>n >>m;
    vector v(m,vi());
    rep(i,0,n) {
        cin >>a[i]; a[i]--;
        v[a[i]].push_back(i);
    }
    vector<pii> qry;
    rep(i,0,m) {
        if(sz(v[i])) {
            rep(j,0,sz(v[i])) {
                int ri = (j+1<sz(v[i])?v[i][j+1]:n);
                if(v[i][j]+1<ri) {
                    qry.push_back({v[i][j]+1,ri});
                }
            }
        }
    }
    ll res = mo(qry);
    cout <<res <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}