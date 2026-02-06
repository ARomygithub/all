#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int mxn=2e6,mxa=1e7,sg=mxn*8;
int n,m,q;
int a[mxn], s[sg], ch[sg][2];
// int ti = 1;
int ss[sg], sn=0;

#define er(x) ss[++sn]=x //erase x for further usage
inline int alc_() //allocate a clean new node
{
    int x=ss[sn--];
    ch[x][0]=ch[x][1]=s[x]=0;
    return x;
}

void build(int& x, int l, int r, int p) {
    x = alc_(); s[x] = 1;
    if(l==r) return;
    int m = (l+r)>>1;
    if(p<=m) build(ch[x][0], l, m, p);
    else build(ch[x][1], m+1,r,p);
}

void split(int t1, int& t2, int k) {
    // assert(k < s[t1]);
    // debug() <<imie(t1) imie(k);
    t2 = alc_();
    if(ch[t1][0]==0 && ch[t1][1]==0) {
        s[t2] = s[t1]-k;
        s[t1] = k;
        return;
    }
    int ls = s[ch[t1][0]];
    // debug() <<imie(s[t1]) imie(s[ch[t1][0]]) imie(s[ch[t1][1]]);
    if(k>ls) split(ch[t1][1], ch[t2][1], k-ls);
    else swap(ch[t1][1],ch[t2][1]);
    if(k<ls) split(ch[t1][0],ch[t2][0],k);
    s[t2] = s[t1]-k;
    s[t1]=k;
}

int merge(int t1, int t2) {
    if(t1&&t2); else return t1^t2;
    ch[t1][0] = merge(ch[t1][0],ch[t2][0]);
    ch[t1][1] = merge(ch[t1][1],ch[t2][1]);
    s[t1] += s[t2]; 
    er(t2);
    // assert(ch[t1][0]!=0 || s[ch[t1][0]]==0);
    return t1;
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
    rep(i,0,m) {
        rep(j,0,n) {
            // cin >>a[i*n+j];
            a[i*n+j] = read<int>();
        }
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
                build(id[x], 1, mxa, a[x*n]);
                rep(j,1,n) {
                    int tmp; 
                    build(tmp, 1, mxa, a[x*n+j]);
                    id[x] = merge(id[x], tmp);
                }
                udh[x] = 1;
            }
            if(!udh[y]) {
                build(id[y], 1, mxa, a[y*n]);
                rep(j,1,n) {
                    int tmp;
                    build(tmp, 1, mxa, a[y*n+j]);
                    id[y] = merge(id[y], tmp);
                }
                udh[y] = 1;
            }
            id[x] = merge(id[x], id[y]);
            split(id[x], id[y], n);
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
                // cout <<ask(id[i], 1, mxa, j+1) <<"\n";
                print(ask(id[i],1,mxa,j+1), '\n');
            }
        }
    }
    // cout <<fixed <<setprecision(10) << (double)(clock() - ts)/CLOCKS_PER_SEC <<endl;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    per(i,sg-1,0) {
        ss[++sn] = i;
    }
    solve();
}