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
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
void min_self(T& a, T b) {
    a = min(a,b);
}

const int mxn = 1e5;
int n;
string t;

struct dt {
    vi l,r;
    int z{}, o{}, s{}, sz{};
    void push(int v) {
        if(v<0) l.push_back(v);
        if(v==0) z++;
        if(v==1) o++;
        if(v>1) r.push_back(v);
        // debug() <<"push " imie(v);
    }
    vi get(int ni) {
        vi v;
        // debug() <<"get " imie(ni);
        v.insert(v.begin(), l.begin(), l.begin()+min(sz(l),ni));
        if(sz(l)<ni) v.insert(v.end(), min(ni-sz(l), z), 0);
        if(sz(v)<ni) v.insert(v.end(), min(ni-sz(v),o), 1);
        if(sz(v)<ni) v.insert(v.end(), r.begin(), r.begin()+ni-sz(v));
        // debug() <<"get " imie(ni);
        return v;
    }
    int size() { return sz(l)+sz(r)+z+o; }
};

void solve() {
    cin >>n;
    cin >>t;
    vector adj(n, vi());
    rep(i,1,n) {
        int p; cin >>p; p--;
        adj[p].push_back(i);
    }
    vi ans(n);
    function<dt(int)> f;
    f = [&](int u) -> dt {
        dt d;
        for(int v: adj[u]) {
            auto r = move(f(v));
            // auto r = f(v);
            if(d.size()==0) {
                swap(d,r);
                continue;
            }
            d.s += r.s;
            d.sz += r.sz;

            dt sw;
            sw.s = d.s, sw.sz=d.sz;

            int size = min(d.size(), r.size());
            vi x = d.get(size), y = r.get(size);
            ans[u] = d.s;
            int sum = d.s;
            rep(i,0,size) {
                sw.push(x[i]+y[i]), sum += x[i]+y[i];
                min_self(ans[u], sum);
            }
            swap(sw, d);
        }
        d.sz++;
        if(t[u]=='1') {
            d.s++;
            d.push(-1);
        } else {
            d.push(1);
        }
        if(sz(adj[u])==1) {
            ans[u] = ans[adj[u][0]];
        }
        return d;
    };
    f(0);
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
}