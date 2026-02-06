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
int n,k;
ll a[mxn*2];
const int inf = 1e9, mxb=18;

vector<vi> binlif(vi& f) {
    vector ret(mxb, vi(sz(f)));
    rep(i,0,sz(f)) {
        ret[0][i] = f[i];
    }
    rep(b,1,mxb) {
        rep(i,0,sz(f)) {
            int nx = ret[b-1][i];
            ret[b][i] = nx==inf?inf:ret[b-1][nx];
        }
    }
    return ret;
}

int jmp(vector<vi>& tbl, int u, int x) {
    rep(i,0,mxb) {
        if((x>>i)&1) {
            u = tbl[i][u];
        }
        if(u==inf) break;
    }
    return u;
}

void solve() {
    cin >>n >>k;
    ll sa = 0;
    rep(i,0,n) {
        cin >>a[i];
        sa += a[i];
    }
    rep(i,n,n*2) {
        a[i] = a[i-n];
    }
    ll l = 1, r = sa;
    int ki = -1, ct = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        int ri = -1;
        ll sm = 0;
        vi f(n*2+1,inf);
        rep(li,0,n*2) {
            while(ri+1<n*2 && sm<mid) {
                ri++;
                sm += a[ri];
            }
            if(sm>=mid) {
                f[li] = ri+1;
            }
            sm -= a[li];
        }
        // debug() <<imie(f);
        auto tbl = binlif(f);
        int cti = 0;
        rep(i,0,n) {
            cti += jmp(tbl, i, k) <= n+i;
        }
        if(cti>0) {
            ki = mid;
            ct = cti;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout <<ki <<" " <<n-ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}