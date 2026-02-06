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

const int mxn=1e5;
int n,q;
ll a[mxn];

const ll inf = 1e15;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll val = 0, mn=0,semn = inf;
    int ctmn;
    Node(int lo,int hi):lo(lo),hi(hi), ctmn(hi-lo) {} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return (l->query(L, R) + r->query(L, R));
    }
    void chmax(int L, int R, ll x) {
        if(R<=lo || hi<=L || mn>=x) return;
        if(L<=lo && hi<=R && semn>x) {
            val += (x-mn)*ctmn;
            mn = x;
        } else {
            push(), l->chmax(L,R,x), r->chmax(L,R,x);
            val = l->val + r->val;
            mn = min(l->mn, r->mn);
            semn = min(l->semn, r->semn);
            ctmn = 0;
            if(mn == l->mn) {
                ctmn += l->ctmn;
            } else {
                min_self(semn, l->mn);
            }
            if(mn == r->mn) {
                ctmn += r->ctmn;
            } else {
                min_self(semn, r->mn);
            }
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        l->chmax(lo,hi, mn);
        r->chmax(lo,hi,mn);
    }
};

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    Node st(0,n);
    vector<pll> v;
    rep(i,0,n) {
        v.push_back({a[i],i});
    }
    sort(all(v));
    pll md = v[sz(v)-1];
    int l = md.se, r = md.se;
    st.chmax(md.se,md.se+1, md.fi);
    per(i,sz(v)-2,-1) {
        auto [val, id] = v[i];
        if(id<l) {
            st.chmax(id,l,val);
            l = id;
        } else if(id>r) {
            st.chmax(r+1,id+1,val);
            r = id;
        }
    }
    ll s = 0;
    rep(i,0,n) {
        s += a[i];
    }
    cin >>q;
    while(q--) {
        ll x,ad; cin >>x >>ad; x--;
        a[x] += ad;
        s += ad;
        if(a[x] > md.fi) {
            st.chmax(x,x+1, a[x]);
            if(x<=md.se) {
                st.chmax(x+1,md.se+1,md.fi);
            } else {
                st.chmax(md.se,x,md.fi);
            }
            md = {a[x], x};
        } else {
            if(x<=md.se) {
                st.chmax(x,md.se+1, a[x]);
            } else {
                st.chmax(md.se+1,x+1,a[x]);
            }
        }
        cout <<st.query(0,n) - s <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >>tc;
    while(tc--) {
        solve();
    }
}