#include <bits/stdc++.h>
using namespace std;

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
int n,q;
int xi[mxn];

ll f(ll le, ll ri) {
    ll len = ri-le;
    return len*(le+ri-1)/2;
}

const ll inf = 0, setc=4e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll mset = setc, madd = 0, val = -inf;
    ll val2 = 0, val3=0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    ll query2(int L, int R) {
        if(R <= lo || hi <= L) return -inf;
        if(L<=lo && hi<=R) return val2;
        push();
        return l->query2(L, R) + r->query2(L,R);
    }
    ll query3(int L, int R) {
        if(R <= lo || hi<=L) return -inf;
        if(L<=lo && hi<=R) return val3;
        push();
        return l->query3(L,R) + r->query3(L,R);
    }
    void set(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            val = x*(hi-lo);
            val2 = x*f(lo+1,hi+1);
            val3 = x*f(n+1-hi, n-lo+1);
            madd = 0;
        }
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
            val2 = l->val2 + r->val2;
            val3 = l->val3 + r->val3;
        }
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != setc) {
                mset += x;
            } else {
                madd += x;
            }
            val += x*(hi-lo);
            val2 += x*f(lo+1,hi+1);
            val3 += x*f(n+1-hi, n-lo+1);
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
            val2 = l->val2 + r->val2;
            val3 = l->val3 + r->val3;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != setc)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = setc;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>xi[i];
    }
    cin >>q;
    Node st(0,n);
    rep(i,0,n) {
        int di = xi[i] - (i>0?xi[i-1]:0);
        st.set(i,i+1,di);
    }
    ll anss = 0;
    while(q--) {
        int t,g; cin >>t >>g; t--;
        ll cur = st.query(0, t+1);
        ll ans = 0;
        // debug() <<imie(cur) imie(t) imie(g);
        if(cur<g) {
            int l=t+1, r = n-1;
            int xj = n;
            while(l<=r) {
                int mid = (l+r)/2;
                ll qry = st.query(0,mid+1);
                if(g+(mid-t)<=qry) {
                    xj = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } 
            ll qry = st.query(0,t+1);
            ll qry0 = st.query(t+1,xj);
            ll qry3 = st.query3(t+1,xj) - qry0*(n-xj);
            ll temp = 1ll*g*(xj-t) - qry*(xj-t)-qry3 + f(1,xj-t);
            ans += temp;
            st.add(t, t+1, g-cur);
            st.set(t+1,xj,1);
            st.add(xj, min(xj+1,n), qry+qry0-(g+(xj-1-t)));
        } else if(cur>g) {
            int l=0, r=t-1;
            int xj = -1;
            while(l<=r) {
                int mid = (l+r)/2;
                ll qry = st.query(0,mid+1);
                if(g-(t-mid) >= qry) {
                    xj = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            ll len = t-xj;
            ll qry = st.query(0,xj+2);
            ll qry3 = st.query3(xj+2,t+1) - st.query(xj+2,t+1)*(n-(t+1));
            ll temp = qry*len + qry3 + f(1,len) - 1ll*g*len;
            ans += temp;
            st.add(xj+1, xj+2, g-(t-xj-1)-qry);
            st.set(xj+2, t+1, 1);
            st.add(t+1, min(t+2,n), cur-g);
        }
        // cout <<ans <<"\n";
        // rep(i,0,n) {
        //     debug() <<imie(st.query(0,i+1));
        // }
        anss += ans;
    }
    cout <<anss <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}