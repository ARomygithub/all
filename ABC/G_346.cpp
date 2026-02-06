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
typedef pair<pii,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const pii inf = {-1e9, 1e9};
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, madd = 0;
    int val = 0, ct = hi-lo;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    pii query(int L, int R) {
        if (R <= lo || hi <= L) return pii({1e9,0});
        if (L <= lo && hi <= R) return pii({val,ct});
        push();
        pii retl = l->query(L, R);
        pii retr = r->query(L, R);
        pii ret = {min(retl.fi,retr.fi), 0};
        if(retl.fi==ret.fi) {
            ret.se += retl.se;
        }
        if(retr.fi==ret.fi) {
            ret.se += retr.se;
        }
        return ret;
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
            ct = 0;
            if(l->val == val) {
                ct += l->ct;
            }
            if(r->val == val) {
                ct += r->ct;
            }
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

const int mxn=2e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> r(n,n),l(n,-1);
    map<int,int> mp;
    per(i,n-1,-1) {
        if(mp.count(a[i])) {
            r[i] = mp[a[i]];
            l[r[i]] = i;
        }
        mp[a[i]] = i;
    }
    ll ans = 0;
    Node st(0,n);
    vector<pipi> v;
    rep(i,0,n) {
        v.push_back({{l[i]+1,1},{i,r[i]}});
        v.push_back({{i+1,-1},{i,r[i]}});
    }
    sort(v.begin(),v.end());
    int id = 0;
    rep(i,0,n) {
        while(id<sz(v) && v[id].fi.fi==i) {
            auto [ev,rn] = v[id];
            st.add(rn.fi,rn.se, ev.se);
            id++;
        }
        auto ret = st.query(0,n);
        int temp = n;
        if(ret.fi==0) {
            temp -= ret.se;
        }
        ans += temp;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}