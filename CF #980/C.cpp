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

const int mxn=2e5;
int n,k,t;
int m[2], b[2][mxn];
vi adj[2][mxn];

vi pi(const vi& s) {
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

vi match(const vi& s, const vi& pat) {
    vi pats(all(pat));
    pats.push_back(-1e9);
    for(auto si: s) {
        pats.push_back(si);
    }
    vi p = pi(pats), res;
    rep(i,sz(p)-sz(s),sz(p))
        if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
    return res;
}

void en() {
    rep(tp,0,2) {
        rep(i,0,n) {
            adj[tp][i].clear();
        }
    }
}

void solve() {
    cin >>n >>k;
    rep(tp,0,2) {
        rep(i,0,n) {
            cin >>b[tp][i];
        }
        cin >>m[tp];
        rep(i,0,m[tp]) {
            int u,v; cin >>u >>v; u--,v--;
            adj[tp][u].push_back(v);
        }
    }
    vector x(2, vi(2,0));
    rep(tp,0,2) {
        rep(i,0,n) {
            x[tp][b[tp][i]]++;
        }
    }
    if(x[0][0]!=x[1][1] || x[0][1]!=x[1][0]) {
        cout <<"NO\n";
        en();
        return;
    }
    if(x[0][0]==0 || x[0][0]==n) {
        cout <<"YES\n";
        en();
        return;
    }
    vector cl(2, vi(n,-1));
    rep(tp,0,2) {
        function<void(int,int)> dfs;
        dfs = [&](int u, int cli) -> void {
            cl[tp][u] = cli;
            for(auto v: adj[tp][u]) {
                if(cl[tp][v]==-1) {
                    dfs(v, (cli+1)%k);
                }
            } 
        };
        dfs(0,0);
        debug() <<imie(tp);
        debug() <<imie(cl[tp]);
    }
    vector ct(2, vector(2, vi(k,0)));
    rep(tp,0,2) {
        rep(i,0,n) {
            ct[tp][b[tp][i]][cl[tp][i]]++;
        }
        debug() <<imie(tp);
        debug() <<imie(ct[tp]);
    }
    auto mat = [&](vi& pt1, vi& pt2) -> vi {
        vi ptn(all(pt2));
        for(auto pti: pt2) {
            ptn.push_back(pti);
        }
        return match(ptn, pt1);
    };
    auto res1 = mat(ct[0][1], ct[1][0]);
    auto res2 = mat(ct[0][0], ct[1][1]);
    debug() <<imie(res1);
    debug() <<imie(res2);
    set<int> s1;
    for(auto r1: res1) {
        s1.insert(r1);
    }
    for(auto r2: res2) {
        if(r2>=k) break;
        if(s1.count((r2+2)%k)) {
            debug() <<imie(r2) imie(((r2+2)%k));
            cout <<"YES\n";
            en();
            return;
        }
    }
    cout <<"NO\n";
    en();
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