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
const ll mod = 998244353;
int n,q;
int pos[mxn];
using pli = pair<ll,int>;

ll fastexpo(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

struct Node {
    array<pli,3> val;
    Node() {
        rep(i,0,3) {
            val[i] = {0ll,i};
        }
    }
    Node(int posi, int id) {
        rep(i,0,3) {
            if(i==posi) {
                val[i] = {0ll,i};
            } else {
                val[i] = {fastexpo(2,id), 3-i-posi};
            }
        }
    }
};

typedef Node T;
T unit = Node();
struct Tree {
    T f(T a, T b) { 
        T ret;
        rep(i,0,3) {
            auto [ct, en] = b.val[i];
            ret.val[i] = {(ct + a.val[en].fi)%mod, a.val[en].se};
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
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>pos[i]; pos[i]--;
    }
    Tree st(n);
    rep(i,0,n) {
        st.update(i, Node(pos[i], i));
    }
    while(q--) {
        char qt; cin >>qt;
        if(qt=='s') {
            int l,r; cin >>l >>r; l--;
            ll qry = st.query(l,r).val[0].fi;
            qry = qry*inv(fastexpo(2,l))%mod;
            cout <<qry <<"\n";
        } else {
            int x,y; cin >>x >>y; x--,y--;
            pos[x] = y;
            st.update(x, Node(y, x));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}