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

const int mxn=1e5,mxq=2e5;
int n,m,q,t;
int ans[mxq];
pii ed[mxq];

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

using ipii = pair<int,pii>;

void slv(RollbackUF& ruf, int st, int en, vector<ipii>& vq) {
    int mid = (st+en)/2;
    int t0 = ruf.time();
    vector<ipii> vq0, vq1;
    rep(i,st,mid) {
        ruf.join(ed[i].fi,ed[i].se);
    }
    for(auto& [id,lr]: vq) {
        auto& [l,r] = lr;
        if(ruf.find(l)==ruf.find(r)) {
            vq0.push_back({id,lr});
            ans[id] = mid;
        } else {
            vq1.push_back({id,lr});
        }
    }
    if(sz(vq0)>0 && mid>st) {
        ruf.rollback(t0);
        slv(ruf, st, mid, vq0);
        rep(i,st,mid) {
            ruf.join(ed[i].fi,ed[i].se);
        }        
    }
    if(sz(vq1)>0 && mid+1<en) {
        slv(ruf,mid+1,en,vq1);
    }
    ruf.rollback(t0);
}

void solve() {
    cin >>n >>m >>q;
    rep(i,0,m) {
        cin >>ed[i].fi >>ed[i].se; ed[i].fi--,ed[i].se--;
    }
    vector<ipii> vq(q);
    rep(i,0,q) {
        vq[i].fi = i;
        int l,r; cin >>l >>r; l--,r--;
        vq[i].se = {l,r};
        ans[i] = m;
    }
    RollbackUF ruf(n);
    slv(ruf, 0, m, vq);
    rep(i,0,q) {
        cout <<ans[i] <<" \n"[i==q-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}