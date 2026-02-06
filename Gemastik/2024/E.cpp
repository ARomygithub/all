#include <bits/stdc++.h>
using namespace std;

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1000;
const ll mod=1e9+7;
int n,k;
int a[mxn];

const int inf = 0, setc=2e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    int mset = setc, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return (l->query(L, R)+ r->query(L, R))%mod;
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x, madd = 0;
            val = 1ll*x*(hi-lo)%mod;
        } 
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = (l->val + r->val)%mod;
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != setc) mset = (mset+x)%mod;
            else madd = (madd+x)%mod;
            val = (val + 1ll*x*(hi-lo)%mod)%mod;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = (l->val + r->val)%mod;
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
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector go(n, vector(n, n));
    rep(i,0,n) {
        rep(j,i+1,n) {
            int sm = a[i]+a[j];
            int it = lower_bound(a,a+n,sm)-a;
            go[i][j] = it;
        }
    }
    // debug() <<imie(go);
    vector dp(n, Node(0,n));
    rep(i,0,n) {
        rep(j,i+1,n) {
            dp[i].set(j,j+1,1);
        }
    }
    ll ans = 0;
    vi kanan(n);
    rep(i,0,n) {
        kanan[i] = i+1;
    }
    rep(len,2,11) {
        if(len>=k) {
            rep(i,0,n) {
                ans = (ans + dp[i].query(i+1,n))%mod;
            }
        }
        vi kanan_new(n,n);
        per(i,n-1,-1) {
            rep(j,kanan[i],n) {
                int ct = dp[i].query(j,j+1);
                dp[j].add(go[i][j], n, ct);
                min_self(kanan_new[j], go[i][j]);
            }
            dp[i].set(kanan[i],n, 0);
        }
        kanan.swap(kanan_new);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}