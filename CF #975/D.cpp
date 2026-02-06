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
    vector<Tree> st;
    st.push_back(Tree((n+1)/2));
    st.push_back(Tree(n/2));
    rep(i,0,n) {
        st[i%2].update(i/2, a[i]);
    }
    set<pii> s;
    s.insert({0,n-1});
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({a[i],i});
    }
    sort(all(v));
    ll ans = 0;
    auto f = [&](int l, int r) -> pll {
        int len = r-l+1;
        ll ret1 = 0, ret2=0;
        ret1 = (len+1)/2;
        if(len%2) {
            ll qry = st[l%2].query(l/2, (r/2)+1);
            max_self(ret2, qry+(len/2)+1);
        } else {
            ll qry = st[l%2].query(l/2, (r-1)/2+1);
            max_self(ret2, qry+(len/2)-1+1);
        }
        if(r==l)  {
            // debug() <<imie(l) imie(r) imie(ret1) imie(ret2);
            return {ret1, ret2-ret1};
        }
        if(len%2) {
            ll qry = st[(l+1)%2].query((l+1)/2, (r-1)/2 + 1);
            max_self(ret2, qry + (len/2)-1 +1);
        } else {
            ll qry = st[(l+1)%2].query((l+1)/2, (r/2)+1);
            max_self(ret2, qry + (len/2)-1 + 1);
        }
        // debug() <<imie(l) imie(r) imie(ret1) imie(ret2);
        return {ret1, ret2-ret1};
    };
    auto [temp, lead] = f(0,n-1);
    multiset<ll> ms;
    ms.insert(lead);
    const int inf = 1e9;
    auto er = [&](int id) -> void {
        auto it = s.lower_bound({id,inf});
        it--;
        auto [l,r] = *it;
        auto flr = f(l,r);
        temp -= flr.fi;
        ms.erase(ms.find(flr.se));
        s.erase(it);
        if(id>l) {
            s.insert({l,id-1});
            auto flid = f(l,id-1);
            temp += flid.fi;
            ms.insert(flid.se);
        }
        if(id<r) {
            s.insert({id+1,r});
            auto fidr = f(id+1,r);
            temp += fidr.fi;
            ms.insert(fidr.se);
        }
    };
    for(int i=0;i<n;) {
        ll mn = v[i].fi;
        int j = i;
        while(j<n && v[j].fi==mn) {
            j++;
        }
        max_self(ans, temp + mn + *(--ms.end()));
        rep(k,i,j) {
            er(v[k].se);
        }
        i =j;
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