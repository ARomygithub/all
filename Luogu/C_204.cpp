#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
	char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p1 = buf, p2 = (p1 + fread(buf, 1, 1 << 21, stdin))) == p1 ? EOF : *p1++)
	template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
	template <typename T> inline void write(T x) { if (!x) return; write<T>(x / 10), putchar((x % 10) ^ '0'); }
	template <typename T> inline void print(T x) { if (x > 0) write<T>(x); else if (x < 0) putchar('-'), write<T>(-x); else putchar('0'); }
	template <typename T> inline void print(T x, char en) { print<T>(x), putchar(en); }
}; using namespace FastIO;
#undef getchar()

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

const int mxn=2e6;
int n,m,q;
int a[mxn], s[mxn*2], ch[mxn*2][2];
int ti = 1;

void build(int& x, int l, int r, int p) {
    x = ti++; s[x] = 1;
    if(l==r) return;
    int m = (l+r)>>1;
    if(p<=m) build(ch[x][0], l, m, p);
    else build(ch[x][1], m+1,r,p);
}

void split(int t1, int& t2, int k) {
    t2 = ti++;
    int ls = s[ch[t1][0]];
    if(k>ls) split(ch[t1][1], ch[t2][1], k-ls);
    else swap(ch[t1][1],ch[t2][1]);
    if(k<ls) split(ch[t1][0],ch[t2][0],k);
    s[t2] = s[t1]-k; s[t1]=k;
}

int merge(int t1, int t2) {
    if(t1&&t2); else return t1^t2;
    ch[t1][0] = merge(ch[t1][0],ch[t2][0]);
    ch[t1][1] = merge(ch[t1][1],ch[t2][1]);
    s[t1] += s[t2]; return t1;
}

int ask(int x, int l, int r, int k) {
    if(l==r) return l;
    int ls = s[ch[x][0]];
    int m = (l+r)>>1;
    if(k>ls) return ask(ch[x][1],m+1,r,k-ls);
    return ask(ch[x][0],l,m,k);
}

void dbg(int x) {
    vi ls;
    function<void(int)> rec;
    rec = [&](int u) -> void {
        if(s[u]==1) {
            ls.push_back(u);
            return;
        }
        if(s[ch[u][0]]) {
            rec(ch[u][0]);
        }
        if(s[ch[u][1]]) {
            rec(ch[u][1]);
        }
    };
    debug() <<imie(x);
    debug() <<imie(ls);
}

void solve() {
    // cin >>n >>m >>q;
    n = read<int>();
    m = read<int>();
    q = read<int>();
    set<pii> st;
    rep(i,0,m) {
        rep(j,0,n) {
            // cin >>a[i*n+j];
            a[i*n+j] = read<int>();
            st.insert({a[i*n+j],i*n+j});
        }
    }
    int idi = 1;
    map<pii,int> mpi;
    map<int,int> imp;
    for(auto ps: st) {
        mpi[ps] = idi++;
        imp[mpi[ps]] = ps.fi;
    }
    vi id(m);
    iota(all(id),0);
    vector<bool> udh(m,0);
    while(q--) {
        int qt; 
        // cin >>qt;
        qt = read<int>();
        if(qt==1) {
            int x,y; 
            // cin >>x >>y;
            x = read<int>();
            y = read<int>();
            x--,y--;

            if(!udh[x]) {
                build(id[x], 1, n*m, mpi[{a[x*n],x*n}]);
                rep(j,1,n) {
                    int tmp;
                    build(tmp, 1, n*m, mpi[{a[x*n+j],x*n+j}]);
                    id[x] = merge(id[x], tmp);
                }
                udh[x] = 1;
            }
            if(!udh[y]) {
                build(id[y], 1, n*m, mpi[{a[y*n],y*n}]);
                rep(j,1,n) {
                    int tmp;
                    build(tmp, 1, n*m, mpi[{a[y*n+j],y*n+j}]);
                    id[y] = merge(id[y], tmp);
                }
                udh[y] = 1;
            }
            // dbg(id[x]);
            // dbg(id[y]);
            id[x] = merge(id[x], id[y]);
            split(id[x], id[y], n);
            // dbg(id[x]);
            // dbg(id[y]);
        } else {
            int i,j; 
            // cin >>i >>j; 
            i = read<int>();
            j = read<int>();
            i--,j--;
            if(!udh[i]) {
                // cout <<a[i*n+j] <<"\n";
                print(a[i*n+j], '\n');
            } else {
                // cout <<imp[ask(id[i], 1, n*m, j+1)] <<"\n";
                print(imp[ask(id[i],1,n*m,j+1)], '\n');
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}