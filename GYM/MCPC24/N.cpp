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

const int mxn=2e5;
int n,t;
int a[mxn];

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
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    rep(i,0,n) {
        s.insert(a[i]);
    }
    map<int,int> mp;
    int idi = 0;
    auto it = s.begin();
    while(it!=s.end()) {
        mp[*it] = idi++;
        it++;
    }
    Tree st(idi);
    vi up(n,1);
    rep(i,0,n) {
        int cur = mp[a[i]];
        int qry = st.query(0,cur);
        max_self(qry, 0);
        up[i] = qry+1;
        st.update(cur, qry+1);
    }
    vi dw(n,1);
    Tree st2(idi);
    per(i,n-1,-1) {
        int cur = mp[a[i]];
        int qry = st2.query(0,cur);
        max_self(qry,0);
        dw[i] = qry+1;
        st2.update(cur, qry+1);
    }
    int ans = 0;
    rep(i,0,n) {
        if(up[i]>1 && dw[i]>1) {
            max_self(ans, up[i]+dw[i]-1);
        }
    }
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