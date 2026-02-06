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

const int mxn=1e6, inf=1e9;
int n, h[mxn];

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    cin >>n;
    Tree st2(n);
    rep(i,0,n) {
        cin >>h[i]; h[i]--;
        st2.update(i, h[i]);
    }
    vi pos(n);
    rep(i,0,n) {
        pos[h[i]] = i;
    }
    Tree st(n);
    int ans = 0;
    rep(i,0,n) {
        int posi = pos[i];
        int l = 0,r=posi;
        int le = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            int qry = st2.query(mid,posi+1);
            if(qry > i) {
                l = mid+1;
            } else {
                le = mid;
                r = mid-1;
            }
        }
        int ri = -1;
        l = posi, r= n-1;
        while(l<=r) {
            int mid = (l+r)/2;
            int qry = st2.query(posi,mid+1);
            if(qry>i) {
                r = mid-1;
            } else {
                ri = mid;
                l = mid+1;
            }
        }
        int d1 = st.query(le,posi);
        int d2 = st.query(posi+1,ri+1);
        int dd = max(d1,d2) +1;
        max_self(dd,0);
        int diam = max(d1+1,0)+max(d2+1,0);
        max_self(ans, diam);
        st.update(posi, dd);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}