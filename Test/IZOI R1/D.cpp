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

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

const int mxn=2e5;
int n,tc;
ll w;
int p[mxn+1], t[mxn+1];

void solve() {
    cin >>n >>w;
    rep(i,2,n+1) {
        cin >>p[i];
    }
    vector<int> ord(n+1,-1);
    vi iord;
    rep(i,1,n) {
        int x; cin >>x >>t[x];
        ord[x] = i;
        iord.push_back(x);
    }
    vi ans(n-1, 0);
    Node st(ans, 0, n-1);
    vi ed;
    rep(i,1,n+1) {
        int u = i, v = (i+1<=n)?i+1:1;
        set<pii> s;
        while(u!=v) {
            if(u<v) {
                s.insert({ord[v],v});
                v = p[v];
            } else {
                s.insert({ord[u],u});
                u = p[u];
            }
        }
        // cout <<i <<endl;
        for(auto it = s.begin();it!=s.end();it++) {
            auto it2 = it; it2++;
            auto [tmu, u2] = *it;
            // auto tn = (it2==s.end()?n:(*it2).fi);
            st.add(tmu-1, n-1, t[u2]);
            // cout <<u2 <<" \n"[it2==s.end()];
        }
        ed.push_back((*(--s.end())).fi);
    }
    sort(ed.begin(), ed.end());
    ll ww = w;
    rep(i,0,n-1) {
        ww -= t[iord[i]];
        ll qry = st.query(i,i+1);
        auto it = ed.end() - upper_bound(ed.begin(), ed.end(), i+1);
        qry += ww*it;
        cout <<qry <<" \n"[i==n-2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>tc;
    while(tc--) {
        solve();
    }
}