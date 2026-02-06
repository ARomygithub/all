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
const ll mod = 998244353;
int n,m,t;


const ll inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = inf, madd = 0, val = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
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
            if (mset != inf) mset = (mset+x)%mod;
            else madd = (madd+x)%mod;
            val = (val+x)%mod;
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

void solve() {
    cin >>n >>m;
    vector<pii> v(m);
    rep(i,0,m) {
        cin >>v[i].fi >>v[i].se;
    }
    sort(all(v));
    Node st(0,n+1);
    multiset<int> ms;
    rep(i,0,m) {
        ms.insert(v[i].se);
    }
    st.add(0,1,1);
    int j = 0;
    rep(i,0,n) {
        ll cur = st.query(i,i+1);
        while(j<m && v[j].fi<i+1) {
            ms.erase(ms.find(v[j].se));
            j++;
        }
        int r = n+1;
        if(sz(ms)) {
            r = *ms.begin();
        }
        st.add(i+1,r,cur);
    }
    cout <<st.query(n,n+1)*2%mod <<"\n";
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