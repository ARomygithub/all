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
int n;
string s;

ll fastexpo(ll x, ll y, ll md) {
    ll ret = 1;
    while(y) {
        if(y&1) ret= ret*x%md;
        x = x*x%md;
        y >>= 1; 
    }
    return ret;
}

ll inv(ll x, ll md) {
    return fastexpo(x, md-2, md);
}

typedef uint64_t ull;
// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
    int x; B b; A(int x=0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
    A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
    A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
    A operator/(A o) { return {(int)(1LL*x*inv(o.x,M)%M), b/o.b}; }
    explicit operator ull() { return x ^ (ull) b << 21; }
    bool operator==(A o) const { return (ull)*this == (ull)o; }
    bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
static int C = rng()%1000000007;
H pw[mxn+1];

struct nd {
    H hs;
    int ct, fs=0,ls=0;
    nd(): hs(0),ct(0) {}
    nd(int x): hs(x),ct(1),fs(x),ls(x) {}
    // void dbg() {
    //     debug() <<imie((ull)hs);
    //     debug() <<imie(ct);
    //     debug() <<imie(fs) imie(ls);
    // }
};

const nd unit = nd();
struct Tree {
    typedef nd T;
    T f(T a, T b) { 
        T ret;
        ret.ct = a.ct+b.ct;
        if(a.ls==1 && b.fs==1) {
            if(a.ct==1 && b.ct==1) {
                // nothing
            } else if(a.ct==1) {
                ret.hs = b.hs - pw[b.ct-1];
                ret.fs = 0;
                ret.ls = b.ls;
            } else if(b.ct==1) {
                ret.hs = (a.hs - H(1))/H(C);
                ret.fs = a.fs;
                ret.ls = 0;
            } else {
                ret.hs = b.hs - pw[b.ct-1];
                H tmp = (a.hs - H(1))/H(C);
                ret.hs = (ret.hs + tmp*pw[b.ct-1]);
                ret.fs = a.fs;
                ret.ls = b.ls;
            }
            ret.ct -= 2;
        } else {
            ret.hs = (b.hs + a.hs*pw[b.ct]);
            ret.fs = a.ct>0?a.fs: b.fs;
            ret.ls = b.ct>0? b.ls: a.ls;
        }
        return ret;
    } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            // debug() <<"ra";
            // ra.dbg();
            // debug() <<"rb";
            // rb.dbg();
            if (b % 2) {
                // debug() <<"s[b]";
                // s[b].dbg();
                ra = f(ra, s[b++]);
            }
            if (e % 2) {
                // debug() <<"s[e-1]";
                // s[e-1].dbg();
                rb = f(s[--e], rb);
            }
            // debug() <<"ra";
            // ra.dbg();
            // debug() <<"rb";
            // rb.dbg();
        }
        return f(ra, rb);
    }
};

void solve() {
    cin >>n;
    cin >>s;
    int q; cin >>q;
    Tree st(n);
    rep(i,0,n) {
        st.update(i, nd(s[i]-'0'));
    }
    // debug() <<imie(C);
    while(q--) {
        int l1,l2,len; cin >>l1 >>l2 >>len;
        l1--,l2--;
        nd n1 = st.query(l1,l1+len);
        nd n2 = st.query(l2,l2+len);
        // debug() <<"n1 n2";
        // n1.dbg();
        // n2.dbg();
        // if((ull)n1.hs == (ull)n2.hs && n1.ct==n2.ct) {
        if(n1.hs.x==n2.hs.x && n1.hs.b.x==n2.hs.b.x && n1.ct==n2.ct) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    }
}

void tes() {
    H a1 = 1;
    debug() <<imie((ull)a1);
    H a01 = 1;
    debug() <<imie((ull)a01);
    H a101 = a1*pw[2]+a01;
    debug() <<imie((ull)a101);
    H a10 = pw[1];
    debug() <<imie((ull)a10);
    H a1011 = (a101 - H(1))/H(C);
    assert((ull)H(C) == (ull)pw[1]);
    debug() <<imie((ull)a1011);
    H b101 = a10*H(C) + H(1);
    debug() <<imie((ull)b101);
    H x1 = a10*H(C);
    H y1 = x1/H(C);
    debug() <<imie((ull)x1);
    debug() <<imie((ull)y1);
    debug() <<imie(y1.x) imie(y1.b.x);
    debug() <<imie(a10.x) imie(a10.b.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pw[0] = 1;
    rep(i,1,mxn+1) {
        pw[i] = pw[i-1]*C;
    }
    // tes();
    solve();
}