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

const int mxn=1e5;
int n,q;

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll val = 0, val2 = 0, xr = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        int len = hi-lo;
        if (R <= 0 || len <= L) return 0;
        if (L <= 0 && len <= R) return val;
        push();
        int mlen = len/2;
        return l->query(L, R) + r->query(L-mlen, R-mlen);
    }
    ll query2(int L, int R) {
        // debug() <<imie(lo) imie(hi);
        // debug() <<imie(L) imie(R);
        // BF agar xr udh kepush semua
        // tp tc3 perlu sekali di awal. tc1 perlu BF.
        // sol: checker apa sudah terpush semua
        // push();
        ll len = hi-lo;
        if(R-L == len) {
            return val2;
        }
        int mid = len/2;
        ll ret = 0;
        if(L < mid) {
            ret += l->query2(L, min(mid,R));
        }  
        if(R > mid) {
            ret += r->query2(max(L,mid) - mid, R-mid);
            if(L < mid) {
                ll mlen = mid-L; 
                ret += r->query(0, R-mid) * mlen;
            }
        }
        // debug() <<imie(lo) imie(hi);
        // debug() <<imie(L) imie(R) imie(ret);
        return ret;
    }
    void set(int L, int x) {
        if (L < lo || hi <= L) return;
        if(lo==L && hi==L+1) {
            val = x;
            val2 = x;
        } else {
            push(); l->set(L,x); r->set(L, x);
            val = l->val + r->val;
            int mlen = (hi-lo)/2;
            val2 = l->val2 + r->val2 + (r->val)*mlen;
        }
    }
    void opxr(int nxr) {
        // push();
        int len = hi-lo;
        int k = 0;
        while(len>1) {
            k++;
            len /= 2;
        } 
        if(k) {
            k--;
            if((nxr>>k)&1) {
                // debug() <<imie(l->val) imie(r->val);
                swap(l,r);
                
                // debug() <<"swapped " <<imie(l->val) imie(r->val);
                nxr = nxr ^ (1<<k);
                int mlen = (hi-lo)/2;
                val2 = l->val2 + r->val2 + (r->val)*mlen;                
            }
            xr ^= nxr;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if(xr) {
            l->opxr(xr), r->opxr(xr), xr = 0;
            int mlen = (hi-lo)/2;
            val2 = l->val2 + r->val2 + (r->val)*mlen;            
        }
    }
    void pushall() {
        push();
        if(l->hi - l->lo > 1) l->pushall();
        if(r->hi -r->lo > 1) r->pushall();
    }
};


void solve() {
    cin >>n >>q;
    Node st(0,n);
    rep(i,0,n) {
        int ai; cin >>ai;
        st.set(i,ai);
    }
    while(q--) {
        int qt; cin >>qt;
        st.pushall();
        if(qt==1) {
            int nxr; cin >>nxr;
            st.opxr(nxr);
        } else if(qt==2) {
            int l,r; cin >>l >>r; r++;
            // st.pushall();
            cout <<st.query(l,r) <<"\n";
        } else {
            int l,r; cin >>l >>r; r++;
            // st.pushall();
            cout <<st.query2(l,r) <<"\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}