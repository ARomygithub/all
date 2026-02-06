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
int n,t;

const pii inf = {1e9,1e9};
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    int madd = 0;
    pii val = {0,0};
    Node(int lo,int hi):lo(lo),hi(hi){
        val = {0,lo};
    } // Large interval of -inf
    pii query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val.fi += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

void solve() {
    cin >>n;
    Node st(0,n+1);
    rep(i,1,n+1) {
        st.add(i,n+1,1);
    }
    ll sa = 0, m = 0;
    rep(i,0,n) {
        int ai; cin >>ai;
        sa += ai;
        m++;
        st.add(ai,n+1,-1);
        pii qry = st.query(0,n+1);
        if(qry.fi<0) {
            st.add(qry.se,n+1,1);
            sa -= qry.se;
            m--;
        }
        cout <<sa - m*(m+1)/2 <<" \n"[i==n-1];
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