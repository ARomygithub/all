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
typedef pair<pii,int> piii;
const int mxn=2e5;
int n;
int l[mxn],r[mxn];

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
        cin >>l[i] >>r[i];
    }
    set<int> sr;
    sr.insert(0);
    rep(i,0,n) {
        sr.insert(r[i]);
    }
    int id = 0;
    map<int,int> mp;
    for(auto sri: sr) {
        mp[sri] = id; id++;
    }
    Tree st(id);
    st.update(0, 0);
    set<piii> s;
    s.insert({{0,0},0});
    rep(i,0,n) {
        auto it = s.upper_bound({{l[i]-1,(int)(2e9)},(int)(2e9)});
        it--;
        auto [pq,len] = *it;
        auto [p,q] = pq;
        int lenn = len-max(q-(l[i]-1), 0) +r[i]-l[i]+1;
        int ln = max(q+1,l[i]);
        auto itr = sr.upper_bound(l[i]-1); itr--;
        int qry = st.query(0,mp[*itr]+1);
        max_self(lenn, qry+r[i]-l[i]+1);
        vector<set<piii>::iterator> erased;
        vector<piii> add;
        if(l[i]<=q && len-(q-(l[i]-1))<qry) {
            erased.push_back(it);
            add.push_back({{p,l[i]-1},len-(q-(l[i]-1))});
            ln = l[i];
        }
        if(ln<=r[i]) {
            it++;
            while(it!=s.end() && (it->fi.fi <=r[i])) {
                auto [li,ri] = it->fi;
                if(ri<=r[i]) {
                    erased.push_back(it);
                } else {
                    erased.push_back(it);

                    piii added = {{r[i]+1,ri}, it->se};
                    add.push_back(added);
                    break;
                }
                it++;
            }
            for(auto it2: erased) {
                s.erase(it2);
            }
            for(auto temp : add) {
                s.insert(temp);
            }
            s.insert({{ln,r[i]},lenn});
            st.update(mp[r[i]], lenn);
        }
    }
    int ans = 0;
    for(auto temp: s) {
        auto [liri,val] = temp;
        max_self(ans, val);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}