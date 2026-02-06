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

const int mxn=2e5,mxa=1e6;
int n,q;
int a[mxn], b[mxa+1];

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn)
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
        b[a[i]]++;
    }
    int lbh = 0;
    rep(i,0,n) {
        lbh += (a[i]>n);
    }
    cin >>q;
    while(q--) {
        int x,y; cin >>x >>y; x--;
        b[a[x]]--;
        lbh -= (a[x]>n);
        a[x] = y;
        b[a[x]]++;
        lbh += (a[x]>n);
        vi dp(n+1,1e9);
        dp[0] = 0;
        vi prefb(n+1,0);
        rep(i,1,n+1) {
            prefb[i] = prefb[i-1] + b[i];
        }
        Tree st1(n+1), st2(n+1);
        st1.update(0, 0);
        st2.update(0,0);
        rep(i,1,n+1) {
            int mid = i - b[i];
            if(mid>0) {
                min_self(dp[i], st1.query(0,mid)+prefb[i-1]);
            }
            if(mid<i) {
                min_self(dp[i], st2.query(mid,i) + prefb[i-1]+b[i]-i);
            }
            st1.update(i, dp[i]-prefb[i]);
            st2.update(i, dp[i]-prefb[i]+i);
        }
        int ans = dp[n] + lbh;
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}