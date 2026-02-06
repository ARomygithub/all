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

const int mxn=4e5;
int n,t;
ll a[mxn],b[mxn];

const ll inf = 1e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = inf, val = inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            min_self(val, x);
            min_self(mset, x);
        }
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
    }
};

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i]; b[i]--;
    }
    Node st(0,n);
    st.set(0,1,0);
    rep(i,0,n-1) {
        if(b[i]>i) {
            ll cur = st.query(i,i+1);
            st.set(i+1,b[i]+1,cur+a[i]);
        }
    }
    ll ans = 0;
    ll pr = 0;
    rep(i,0,n) {
        pr += a[i];
        max_self(ans, pr - st.query(i,i+1));
    }
    cout <<ans <<"\n";
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