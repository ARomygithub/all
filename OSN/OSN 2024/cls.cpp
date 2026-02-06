#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

using ipii = pair<int,pii>;
const int mxn=1e5;
int n;
pii p[mxn];

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};
const int inf = 1e9;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>p[i].fi >>p[i].se;
    }
    UF uf(n);
    vector<pii> vx,vy;
    rep(i,0,n) {
        vx.push_back({p[i].fi,i});
        vy.push_back({p[i].se,i});
    }
    sort(all(vx));
    sort(all(vy));
    debug() <<imie(vx);
    debug() <<imie(vy);
    vi l(n),r(n);
    rep(i,0,n) {
        auto it = lower_bound(all(vx),pii{vy[i].fi-2,-1})-vx.begin();
        l[i] = it;
        auto it2 = upper_bound(all(vx), pii{vy[i].fi+2,inf})-vx.begin();
        r[i] = it2-1;
    }
    debug() <<imie(l);
    debug() <<imie(r);
    int ls = -1;
    rep(i,0,n) {
        auto [y, id] = vy[i];
        if(l[i]<=r[i]) {
            per(j,r[i],l[i]-1) {
                auto [x, id2] = vx[j];
                debug() <<"join " <<imie(id) imie(id2);
                uf.join(id,id2);
                if(ls>=x) break;
            }
            ls = vx[r[i]].fi;
        }
    }
    map<int,set<int>> mp;
    rep(i,0,n) {
        int lead = uf.find(i);
        mp[lead].insert(i);
    }
    cout <<sz(mp) <<"\n";
    for(auto [lead,s] : mp) {
        for(auto si : s) {
            cout <<si <<" ";
        }
        cout <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}