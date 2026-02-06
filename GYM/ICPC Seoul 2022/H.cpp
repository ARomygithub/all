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

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

void solve() {
    cin >>s;
    n = sz(s);
    SuffixArray sa(s);
    RMQ<int> rmq(sa.lcp);
    vector<pii> ans(n,{0,0});
    ans[0] = {1,n};
    set<int> st;
    int la=-1,ra=-1;
    auto eval = [&](int lenj) -> pii {
        int notoverlap = 0;
        int r = -1;
        while(true) {
            auto it = st.upper_bound(r);
            if(it==st.end()) {
                break;
            } else {
                notoverlap++;
                r = (*it)+lenj-1;
            }
        }
        return {notoverlap,lenj};
    };
    ll ct = 0;
    rep(i,1,n) {
        int start = sa.sa[i];
        // if(ra<i) {
        //     la = i, ra=i;
        //     st.clear();
        //     st.insert(start);
        // }
        // int len = n-start;
        rep(lenj,sa.lcp[i]+1,sa.lcp[i+1]+1) {
            int ri = i+1;
            int l=i+1, r=n;
            while(l<=r) {
                int mid = (l+r)/2;
                int qry = rmq.query(i+1,mid+1);
                if(qry>=lenj) {
                    ri = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            int k = ri-i+1;
            // if(ra<=ri) {
            //     // debug() <<"1";
            //     rep(j,ra+1,ri+1) {
            //         st.insert(sa.sa[j]);
            //     }                
            //     ra = ri;
            // } else if(ra-ri < ri-la+1) {
            //     // debug() <<"2";
            //     // debug() <<imie(la) imie(ri);
            //     per(j,ra,ri) {
            //         st.erase(sa.sa[j]);
            //     }
            //     ra = ri;
            // } else {
            //     // debug() <<"3";
            //     st.clear();
            //     rep(j,la,ri+1) {
            //         st.insert(sa.sa[j]);
            //     }
            //     ra = ri;
            // }
            // debug() <<imie(la) imie(ra) imie(sz(st));
            ct++;
            // if(ra-la+1!=sz(st)) {
            //     debug() <<imie(la) imie(ra) imie(sz(st));
            //     assert(false);
            // }
            // assert(ra-la+1 == sz(st));
            // max_self(ans[k-1], eval(lenj));
        }
        // st.erase(start);
        // la++;
    }
    debug() <<imie(ct);
    // rep(i,0,n) {
    //     cout <<ans[i].se <<" \n"[i==n-1];
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}