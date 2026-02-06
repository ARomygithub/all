#include <bits/stdc++.h>
using namespace std;

#pragma once
#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
int n,m,p;
pii a[mxn],b[mxn];

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
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

using piii = pair<pii,int>;

void solve() {
    cin >>n >>m >>p;
    rep(i,0,n) {
        cin >>a[i].fi >>a[i].se;
        a[i].se *=-1;
    }
    rep(i,0,m) {
        cin >>b[i].fi >>b[i].se;
        b[i].se *= -1;
    }
    sort(a,a+n);
    sort(b,b+m);
    vector<pii> va,vb;
    rep(i,0,n) {
        while(sz(va)) {
            auto [af,as] = va.back();
            if(a[i].fi>=af && a[i].se>=as) {
                va.pop_back();
            } else {
                break;
            }
        }
        va.push_back(a[i]);
    }
    rep(i,0,m) {
        while(sz(vb)) {
            auto [bf, bs] = vb.back();
            if(b[i].fi>=bf && b[i].se>=bs) {
                vb.pop_back();
            } else {
                break;
            }
        }
        vb.push_back(b[i]);
    }
    // debug() <<imie(va);
    // debug() <<imie(vb);
    vector<piii> vm;
    rep(i,0,p) {
        int x,y,z; cin >>x >>y >>z;
        vm.push_back({{x,y},z});
    }
    sort(all(vm));
    int idx = 0;
    Node st(0,sz(vb));
    rep(i,0,sz(vb)) {
        st.set(i,i+1,vb[i].se);
    }
    int ans = -2e9;
    rep(i,0,sz(va)) {
        while(idx<sz(vm) && vm[idx].fi.fi<va[i].fi) {
            auto it = upper_bound(all(vb),pii{vm[idx].fi.se,inf})-vb.begin();
            st.add(it, sz(vb), vm[idx].se);
            idx++;
        }
        int qry = st.query(0,sz(vb));
        max_self(ans, qry + va[i].se);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}