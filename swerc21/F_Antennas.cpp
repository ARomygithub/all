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
int n,a,b,t;
int p[mxn];

struct Tree {
    typedef pii T;
    static constexpr T unit = {INT_MIN,INT_MIN};
    T f(T a, T b) { return max(a,b); }
    vector<T> s; int n;
    Tree(int n=0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for(s[pos += n] = val; pos /= 2;) {
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for(b+=n, e+=n; b < e; b/=2, e/=2) {
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra,rb);
    }
};

void solve() {
    cin >>n >>a >>b; a--,b--;
    rep(i,0,n) {
        cin >>p[i];
    }
    Tree lhs(n), rhs(n);
    rep(i,0,n) {
        lhs.update(i,{i+p[i],i});
        rhs.update(i,{p[i]-i,i});
    }
    vi dp(n,1e9);
    queue<int> q;
    dp[a] = 0;
    lhs.update(a,{INT_MIN,a});
    rhs.update(a,{INT_MIN,a});
    q.push(a);
    while(sz(q)) {
        auto u = q.front(); q.pop();
        while(true) {
            auto [val,id] = lhs.query(max(0,u-p[u]),u);
            if(val>=u) {
                dp[id] = dp[u]+1;
                lhs.update(id,{INT_MIN,id});
                rhs.update(id,{INT_MIN,id});
                q.push(id);
            } else {
                break;
            }
        }
        while(true) {
            auto [val, id] = rhs.query(u+1,min(n,u+p[u]+1));
            if(val>=-u) {
                dp[id] = dp[u]+1;
                rhs.update(id,{INT_MIN,id});
                lhs.update(id,{INT_MIN,id});
                q.push(id);
            } else {
                break;
            }
        }
    }
    cout <<dp[b] <<"\n";
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