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

const int mxn=5e4;
int n;
string s;

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
    }
};

struct UF {
    vi e, vl, vr;
    vector<set<int>> vs;
    UF(int n) : e(n, -1), vs(n),vl(n),vr(n) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        for(auto bs : vs[b]) {
            vs[a].insert(bs);
        }
        min_self(vl[a],vl[b]);
        max_self(vr[a],vr[b]);
        return true;
    }
};

void solve() {
    cin >>s;
    n = sz(s);
    SuffixArray sa(s);
    vector<pii> ans(n,{0,0});
    ans[0] = {1,n};
    UF uf(n+1);
    vector<pii> v;
    rep(i,1,n+1) {
        v.push_back({sa.lcp[i],i});
    }
    sort(all(v),greater<pii>());
    rep(i,1,n+1) {
        uf.vs[i].insert(sa.sa[i]);
        if(i>1) {
            uf.vs[i].insert(sa.sa[i-1]);
        }
        uf.vl[i] = i;
        uf.vr[i] = i;
    }
    auto nonoverlap = [&](set<int>& si, int leni) -> int {
        int ret = 0;
        int en = -1;
        while(true) {
            auto it = si.upper_bound(en);
            if(it==si.end()) break;
            ret++;
            en = (*it)+leni-1;
        }
        return ret;
    };
    for(int i=0;i<sz(v);) {
        if(v[i].fi==0) break;
        int j = i;
        while(j<sz(v) && v[j].fi==v[i].fi) {
            j++;
        }
        rep(k,i,j) {
            auto [lcpi, ord] = v[k];
            if(ord>1) {
                if(sa.lcp[ord-1]>=lcpi) {
                    uf.join(ord-1,ord);
                }
            }
            if(ord+1<=n) {
                if(sa.lcp[ord+1]>=lcpi) {
                    uf.join(ord,ord+1);
                }
            }
        }
        set<int> slead;
        rep(k,i,j) {
            auto [lcpi, ord] = v[k];
            int lead = uf.find(ord);
            slead.insert(lead);
        }
        int lcpi = v[i].fi;
        for(auto lead : slead) {
            int bwh = 0;
            int le = uf.vl[lead], ri = uf.vr[lead];
            if(le>1) {
                // okle = sa.lcp[le-1]<lcpi;
                max_self(bwh, sa.lcp[le-1]);
            }
            if(ri+1<=n) {
                // okri = sa.lcp[ri+1]<lcpi;
                max_self(bwh, sa.lcp[ri+1]);
            }
            // if(okle && okri) {
            int ki = ri-le+1;
            int dmax = nonoverlap(uf.vs[lead],bwh+1);
            int l = bwh+1, r=lcpi;
            int mx = bwh+1;
            while(l<=r) {
                int mid = (l+r)/2;
                int dmid = nonoverlap(uf.vs[lead],mid);
                if(dmid==dmax) {
                    mx = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            // cout <<dmax <<" " <<mx <<"\n";
            max_self(ans[ki], {dmax,mx});
            // }
        }
        i = j;
    }
    rep(i,0,n) {
        cout <<ans[i].se <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}