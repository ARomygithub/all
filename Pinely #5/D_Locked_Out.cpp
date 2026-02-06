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

const int mxn=3e5;
int n,t;
int a[mxn];

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
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
    rep(i,0,n) {
        cin >>a[i];
    }
    vector id(n+1,vi());
    rep(i,0,n) {
        id[a[i]].push_back(i);
    }
    int ls = 0;
    Tree st(n+1);
    rep(val,1,n+1) {
        if(sz(id[val])) {
            if(ls<val-1) {
                int mx = st.query(0,n+1);
                st.update(n, mx);
            }
            set<int> stt;
            vector<pii> upd;
            int mx = st.query(0,n+1);
            upd.push_back({n,mx});
            per(j,sz(id[val])-1,-1) {
                int bj = id[val][j];
                int qry = st.query(bj+1,n+1) - ((sz(id[val]))-j-1);
                stt.insert(qry);
                upd.push_back({bj, (*(--stt.end())) + sz(id[val]) - j});
            }
            for(auto& [pos,vali]: upd) {
                st.update(pos,vali);
            }
            ls = val;
        }
    }
    int ans = n - st.query(0,n+1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}