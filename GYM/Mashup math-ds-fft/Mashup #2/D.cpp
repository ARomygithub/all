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
int n,q;
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

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    Tree st(n);
    vi l(q+1,1e9),r(q+1,-1e9);
    set<int> pos;
    rep(i,0,n) {
        if(a[i]) {
            st.update(i,a[i]);
            min_self(l[a[i]],i);
            max_self(r[a[i]],i);
        } else {
            pos.insert(i);
        }
    }
    if(l[q]>r[q]) {
        if(sz(pos)>0) {
            auto iq = *pos.begin(); pos.erase(pos.begin());
            a[iq] = q;
            st.update(iq,a[iq]);
            l[q] = iq;
            r[q] = iq;
        } else {
            cout <<"NO\n";
            return;
        }
    }
    rep(i,2,q+1) {
        if(l[i]<=r[i]) {
            int mn = st.query(l[i],r[i]);
            if(mn<i) {
                cout <<"NO\n";
                return;
            }
        }
    }
    l[1] = 0,r[1]=n-1;
    per(i,q,0) {
        auto it = pos.lower_bound(l[i]);
        vi er;
        while(it!=pos.end() && (*it)<=r[i]) {
            a[*it] = i;
            er.push_back(*it);
            it++;
        }
        for(auto eri : er) {
            pos.erase(eri);
        }
    }
    cout <<"YES\n";
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}