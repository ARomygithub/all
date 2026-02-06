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

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    bool mflip = 0;
    int mset = -1, val = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = x, val = (hi-lo)*x, mflip = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void flip(int L, int R) {
        if(R<=lo || hi<=L) return;
        if(L<=lo && hi<=R) {
            if(mset!=-1) {
                mset = 1-mset;
                mflip = 0;
            } else {
                mflip = !mflip;
            }
            val = (hi-lo)-val;
        } else {
            push(), l->flip(L,R), r->flip(L,R);
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != -1)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = -1;
        else if(mflip)
            l->flip(lo,hi), r->flip(lo,hi), mflip = 0;
    }
};

const int mxn=1e5;
int n,q;
int a[mxn];

auto compress_coords(auto& coords) {
    vi original;
    original.reserve(sz(coords));
    ranges::sort(coords);
    int idx = -1, prev = -1e9;
    for(auto& x : coords) {
        if(x!= prev) {
            idx++;
            prev = x;
            original.push_back(x);
        }
        x.get() = idx;
    }
    return original;
}

void solve() {
    cin >>n >>q;
    vector<reference_wrapper<int>> coords;
    rep(i,0,n) {
        cin >>a[i];
        coords.push_back(ref(a[i]));
    }
    const int inf = 2e5;
    vector<pii> v0,v1;
    rep(i,0,q) {
        char qt; int x; cin >>qt >>x;
        if(qt=='<') {
            v0.push_back({-inf,x-1});
            v1.push_back({-x+1,inf});
        } else {
            v0.push_back({x+1,inf});
            v1.push_back({-inf,-x-1});
        }
    }
    for(auto& [l,r]: v0) {
        coords.push_back(ref(l));
        coords.push_back(ref(r));
    }
    for(auto& [l,r]: v1) {
        coords.push_back(ref(l));
        coords.push_back(ref(r));
    }
    auto val = compress_coords(coords);
    Node st(0,sz(val));
    rep(i,0,q) {
        int le = max(v0[i].fi,v1[i].fi);
        int ri = min(v0[i].se, v1[i].se);
        if(le<=ri) {
            st.flip(le,ri+1);
            if(v0[i].se==ri) {
                v0[i].se = le-1;
                v1[i].fi = ri+1;
            } else {
                v0[i].fi = ri+1;
                v1[i].se = le-1;
            }
        }
        st.set(v0[i].fi, v0[i].se+1, 1);
        st.set(v1[i].fi, v1[i].se+1, 0);
    }
    vi ans(n);
    rep(i,0,n) {
        if(st.query(a[i],a[i]+1)) {
            ans[i] = -val[a[i]];
        } else{
            ans[i] = val[a[i]];
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}