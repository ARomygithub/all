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

const int mxn=2e5;
int n,q,t;
int a[mxn];

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

ll cal(ll u) {
    return u*(u+1)/2;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<int> bst(n,0);
    vector<ll> pref(n,0);
    bst[0] = 1;
    pref[0] = 1;
    rep(i,1,n) {
        bst[i] = min(bst[i-1]+1,a[i]);
        pref[i] = pref[i-1]+bst[i];
    }
    Tree sta(n);
    rep(i,0,n) {
        sta.update(i,a[i]-i);
    }
    vector<ll> track(n+1,0);
    auto getNext = [&](ll l, ll r, ll tar) -> ll {
        int ret = -1;
        int awl = l;
        while(l<=r) {
            ll mid =(l+r)/2;
            if(sta.query(awl,mid+1)>=tar) {
                ret = mid, l=mid+1;
            } else {
                r = mid-1;
            }
        }
        return ret;
    };
    per(i,n-1,-1) {
        int nxt = getNext(i,n-1,a[i]-i);
        track[i] = track[nxt+1]+cal(a[i]+nxt-i)-cal(a[i]-1);
        cout <<track[i] <<"\n" <<flush;
    }
    cin >>q;
    while(q--) {
        int p,x; cin >>p >>x; p--;
        ll tar = min(x,(p>0?bst[p-1]:0)+1);
        int nxt = getNext(p+1,n-1,tar-p);
        ll ans = p>0?pref[p-1]:0ll + nxt>0?track[nxt+1]:0ll + cal(tar+nxt-p)-cal(tar-1);
        cout <<ans <<"\n" <<flush;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}