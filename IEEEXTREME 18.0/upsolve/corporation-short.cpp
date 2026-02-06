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
int v[mxn];
 
const ll inf = 1e18;
struct Nd {
    ll mx = 0, semx = -inf, mn = 0, semn = inf;
    int ctn=0,ctx=0;
    ll madd=0, mbn=0,mbx=0,ma2=0;
    ll sm=0,sm2=0;
    Nd() {}
    Nd(int lo, int hi) {
        ctn = hi-lo;
        ctx = hi-lo;
    }
};
Nd merge(Nd a, Nd b) {
    Nd ret;
    ret.sm = a.sm + b.sm;
    ret.sm2 = a.sm2 + b.sm2;
    ret.mx = max(a.mx, b.mx);
    ret.semx = max(a.semx, b.semx);
    if(ret.mx == a.mx) {
        ret.ctx += a.ctx;
    } else {
        max_self(ret.semx, a.mx);
    }
    if(ret.mx == b.mx) {
        ret.ctx += b.ctx;
    } else {
        max_self(ret.semx, b.mx);
    }
    ret.mn = min(a.mn,b.mn);
    ret.semn = min(a.semn,b.semn);
    if(ret.mn == a.mn) {
        ret.ctn += a.ctn;
    } else {
        min_self(ret.semn, a.mn);
    }
    if(ret.mn == b.mn) {
        ret.ctn += b.ctn;
    } else {
        min_self(ret.semn, b.mn);
    }
    return ret;
}
void dbg(Nd a) {
    debug() <<imie(a.mn) imie(a.semn) imie(a.ctn) imie(a.mbx);
    debug() <<imie(a.mx) imie(a.semx) imie(a.ctx) imie(a.mbn);
    debug() <<imie(a.sm) imie(a.sm2);
    debug() <<imie(a.madd) imie(a.ma2);
}
 
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    Nd nd;
    Node(int lo,int hi):lo(lo),hi(hi), nd(lo,hi){} // Large interval of -inf
    ll query1(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return nd.sm;
        push();
        return l->query1(L,R) + r->query1(L,R);
    }
    ll query2(int L, int R) {
        if(R<=lo || hi<=L) return 0;
        if(L<=lo && hi<=R) return nd.sm2;
        push();
        return l->query2(L,R) + r->query2(L,R);
    }
    void chmin(int L,int R, ll x, ll y) {
        if(R<=lo || hi<=L || nd.mx<=x) {
            return;
        }
        if(L<=lo && hi<=R && nd.semx<x) {
            nd.mbn += y;
            if(nd.mn==nd.mx) {
                if(nd.mbx && hi-lo>1) {
                    // debug() <<"chmin";
                    // debug() <<imie(lo) imie(hi);
                    // dbg(nd);
                    nd.ma2 += nd.mbx-nd.mbn;
                    nd.madd = 0;
                    nd.mbn = 0;
                    nd.mbx = 0;
                } 
                nd.mn = x;
            }
            if(nd.semn == nd.mx) {
                nd.semn = x;
            }
            nd.sm -= 1ll*(nd.mx-x)*nd.ctx;
            nd.sm2 -= nd.ctx*y;
            nd.mx = x;
            // debug() <<"chmin" imie(lo) imie(hi);
            // dbg(nd);
        } else {
            push(); l->chmin(L,R,x,y), r->chmin(L,R,x,y);
            nd = merge(l->nd,r->nd);
            // debug() <<"chmin" imie(lo) imie(hi);
            // dbg(nd);
        }
    }
    void chmax(int L, int R, ll x, ll y) {
        if(R<=lo || L>=hi || nd.mn>=x) return;
        if(L<=lo && R>=hi && nd.semn>x) {
            nd.mbx += y;
            if(nd.mx==nd.mn) {
                if(nd.mbn && hi-lo>1) {
                    // debug() <<"chmax";
                    nd.ma2 += nd.mbx - nd.mbn;
                    nd.madd = 0;
                    nd.mbx = 0;
                    nd.mbn = 0;
                }
                nd.mx = x;
            }
            if(nd.semx==nd.mn) {
                nd.semx = x;
            }
            nd.sm += 1ll*(x-nd.mn)*nd.ctn;
            nd.sm2 += nd.ctn*y;
            nd.mn = x;
            // debug() <<"chmax" imie(lo) imie(hi);
            // dbg(nd);
        } else {
            push(); l->chmax(L,R,x,y), r->chmax(L,R,x,y);
            nd = merge(l->nd, r->nd);
            // debug() <<"chmax" imie(lo) imie(hi);
            // dbg(nd);
        }
    }
    void add(int L, int R, ll x, ll y) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            nd.mn += x;
            nd.mx += x;
            if(nd.semn!=inf) {
                nd.semn += x;
            }
            if(nd.semx!=-inf) {
                nd.semx += x;
            }
            nd.madd += x;
            nd.ma2 += y;
            nd.sm += x*(hi-lo);
            nd.sm2 += y*(hi-lo);
        }
        else {
            push(), l->add(L, R, x, y), r->add(L, R, x, y);
            nd = merge(l->nd,r->nd);
        }
    }
    void push() {
        // debug() <<"push";
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (nd.madd!=0 || nd.ma2!=0)
            l->add(lo,hi,nd.madd,nd.ma2), r->add(lo,hi,nd.madd,nd.ma2), nd.madd=0, nd.ma2=0;
        // debug() <<imie(lo) imie(hi) imie(nd.mbn) imie(nd.mbx);
        // dbg(l->nd);
        // dbg(r->nd);
        l->chmin(lo, hi, nd.mx, nd.mbn);
        r->chmin(lo, hi, nd.mx, nd.mbn);
        nd.mbn = 0;
        l->chmax(lo, hi, nd.mn, nd.mbx);
        r->chmax(lo, hi, nd.mn, nd.mbx);
        nd.mbx = 0;
    }
    void dbgst() {
        debug() <<imie(lo) imie(hi);
        dbg(nd);
        if(l) l->dbgst();
        if(r) r->dbgst();
    }
    void dbgst2(int L, int R) {
        debug() <<imie(lo) imie(hi);
        dbg(nd);
        if(lo==L && hi==R) {
            return;
        }
        if(l->hi>=R) {
            l->dbgst2(L,R);
        } else {
            r->dbgst2(L,R);
        }
    }
};
 
int sgn(int t) {
    return (t>0)-(t<0);
}
 
void solve() {
    cin >>n >>q;
    rep(i,0,n){
        cin >>v[i];
    }
    Node st(0,n);
    rep(i,0,n) {
        st.add(i,i+1,v[i],1);
    }
    while(q--) {
        // debug() <<"qry";
        int qt; cin >>qt;
        int l,r; cin >>l >>r; l--,r--;
        if(qt==0) {
            int c; cin >>c;
            st.chmin(l,r+1, c, 1);
            st.chmax(l,r+1, c, 1);
        } else if(qt==1) {
            int c; cin >>c;
            if(c!=0) {
                st.add(l,r+1, c, sgn(c));
            }
        } else if(qt==2) {
            ll qry = st.query1(l,r+1);
            ll qb = r+1-l;
            ll d = gcd(abs(qry),qb);
            qry /= d; qb /=d;
            cout <<qry <<"/" <<qb <<"\n";
        } else {
            ll qry = st.query2(l,r+1);
            ll qb = r+1-l;
            qry -= qb;
            ll d = gcd(abs(qry),qb);
            qry /= d; qb /= d;
            cout <<qry <<"/" <<qb <<"\n"; 
        }
        st.dbgst2(3,4);
    }
    // st.dbgst();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}