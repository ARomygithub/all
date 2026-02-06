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

const int mxn=1e6;
int n,m,t;
int a[mxn],b[mxn];

const pii inf = {1e9,-1};
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    pii val;
    int madd = 0;
    Node(int lo,int hi):lo(lo),hi(hi),val({0,lo}){} // Large interval of -inf
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

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    sort(b,b+m);
    Node st(0,n+1);
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({a[i],i});
    }
    sort(all(v));
    rep(i,0,n) {
        auto [val, id] = v[i];
        st.add(id+1,n+1,1);
    }
    int ids = 0, idl=0;
    ll ans = 0;
    // int ls = -1;
    rep(j,0,m) {
        while(idl<n && v[idl].fi<=b[j]) {
            st.add(v[idl].se+1,n+1,-1);
            idl++;
        }
        while(ids<n && v[ids].fi<b[j]) {
            st.add(0,v[ids].se+1,1);
            ids++;
        }
        auto qry = st.query(0,n+1);
        // assert(qry.se>=ls);
        // ls = qry.se;
        ans += qry.fi;
    }
    // int id = 0;
    // map<int,int> mp;
    // set<int> s;
    // rep(i,0,n) {
    //     s.insert(a[i]);
    // }
    // auto it = s.begin();
    // while(it!=s.end()) {
    //     mp[*it] = id++;
    //     it++;
    // }
    // rep(i,0,n) {
    //     int cur = mp[a[i]];
    //     ans += i - ft.query(cur+1);
    //     ft.update(cur,1);
    // }
    FT ft(n);
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && v[j].fi==v[i].fi) {
            j++;
        }
        rep(k,i,j) {
            ans += i - ft.query(v[k].se);
        }
        rep(k,i,j) {
            ft.update(v[k].se, 1);
        }
        i = j;
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