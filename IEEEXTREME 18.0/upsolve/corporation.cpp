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
    vector<ll> tmp = {a.mx,b.mx,a.semx,b.semx};
    sort(all(tmp),greater<ll>());
    ret.mx = tmp[0], ret.semx = tmp[1];
    if(ret.mx == a.mx) {
        ret.ctx += a.ctx;
    }
    if(ret.mx == b.mx) {
        ret.ctx += b.ctx;
    }
    vector<ll> tmpn = {a.mn,b.mn,a.semn,b.semn};
    sort(all(tmpn));
    ret.mn = tmpn[0], ret.semn = tmpn[1];
    if(ret.mn == a.mn) {
        ret.ctn += a.ctn;
    }
    if(ret.mn == b.mn) {
        ret.ctn += b.ctn;
    }
    return ret;
}
void dbg(Nd a) {
    debug() <<imie(a.mn) imie(a.semn) imie(a.ctn) imie(a.mbx);
    debug() <<imie(a.mx) imie(a.semx) imie(a.ctx) imie(a.mbn);
    debug() <<imie(a.sm) imie(a.sm2);
    debug() <<imie(a.madd) imie(a.ma2);
}

// range add, range set (chmin and chmax ga sih).
// query range sum_1, sum_2
// count increase-decrease?
// break condi: R<=lo || hi<=L || mn >=x
// tag condi: L<=lo && hi<=R && semn>=x
// jadi udh tau ubah mn sebanyak ctn ke x.
// Yakin ketika additional sejalan dengan decrease nya phi+. Lalu prove phi+ <= q lg n lg c
// simpen mn,semn,mx,semx,ctn,ctx
// madd, mset.
// sm, sm2
// chmin. mx, semx. ketika tinggal ubah mx -> x. semx ga berubah. jadi aman . lah iya gitu aja.
// 1. chmin. x>=semx && x<mx. mx = x. mn,semn perlu cek ga? if mn=mx sama semn=mx aja. sm -= . sm2 -= . lazy? gimn yah. chmin x1, chmin x2, chmin x3. kl x2>=x1 bisa ignore. kl x2<x1, bisa dipastikan semx<=x2,x1 jadi cukup bobot nya aja.
// add lalu chmin = always dahulukan add.
// kl chmin,chmax,chmin,chmax. lalu kita akumulasi chmin ada problem ga?
// x1 , y1, x2. x1>=y1 ga da problem. x1<y1: hasil akhir y1,..y1 terus jadi x2..x2 
// opsi lain adalah lazy taro ke vector. Terus nge push sampai sejumlah vector.
// di jiry17 dia itu ada A[], C[], B[]. 
// menariknya si peltorator, ga nyimpen lazy tambahan u/ chmin,chmax. dia pake .mx,.mn si parent. yah kasus x1<y1 itu ga mungkin terjadi krn y1<semn,y1>mx, selain dia satu elm, yg artinya ga perlu nge push.
// 2. chmax
// 3. range add. biasa aja. semn=-inf jgn ditambah. lazy berkombinasi gitu gimn.
// chmin lalu add = add lalu chmin (x+add). sm2 += size
// 4. qry range sum_1. dari sm aja
// 5. qry range sum_2. dari sm2 aja
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
        if(R<=lo || hi<=L || nd.mx<=x) return;
        if(L<=lo && hi<=R && nd.semx<x) {
            if(nd.mn==nd.mx) {
                nd.mn = x;
            }
            if(nd.semn == nd.mx) {
                nd.semn = x;
            }
            nd.sm -= 1ll*(nd.mx-x)*nd.ctx;
            nd.sm2 -= nd.ctx*y;
            nd.mx = x;
            nd.mbn += y;
        } else {
            push(); l->chmin(L,R,x,y), r->chmin(L,R,x,y);
            nd = merge(l->nd,r->nd);
        }
    }
    void chmax(int L, int R, ll x, ll y) {
        if(R<=lo || L>=hi || nd.mn>=x) return;
        if(L<=lo && R>=hi && nd.semn>x) {
            if(nd.mx==nd.mn) {
                nd.mx = x;
            }
            if(nd.semx==nd.mn) {
                nd.semx = x;
            }
            nd.sm += 1ll*(x-nd.mn)*nd.ctn;
            nd.sm2 += nd.ctn*y;
            nd.mn = x;
            nd.mbx += y;
        } else {
            push(); l->chmax(L,R,x,y), r->chmax(L,R,x,y);
            nd = merge(l->nd, r->nd);
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
            nd.sm2 += y*(hi-lo); // wait madd kl di akumul sm2 nya jd under counting.
            // debug() <<imie(lo) imie(hi);
            // dbg(nd);
        }
        else {
            push(), l->add(L, R, x, y), r->add(L, R, x, y);
            nd = merge(l->nd,r->nd);
            // debug() <<imie(lo) imie(hi);
            // dbg(nd);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (nd.madd!=0 || nd.ma2!=0)
            l->add(lo,hi,nd.madd,nd.ma2), r->add(lo,hi,nd.madd,nd.ma2), nd.madd=0, nd.ma2=0;
        if(nd.mbn) {
            l->chmin(lo, hi, nd.mx, nd.mbn);
            r->chmin(lo, hi, nd.mx, nd.mbn);
            nd.mbn = 0;
        }
        if(nd.mbx) {
            l->chmax(lo, hi, nd.mn, nd.mbx);
            r->chmax(lo, hi, nd.mn, nd.mbx);
            nd.mbx = 0;
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
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}