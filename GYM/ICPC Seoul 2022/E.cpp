#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
using ipii = pair<int,pii>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e4;
int n,m,k;
map<int,int> ed[mxn];

void solve() {
    cin >>m >>n >>k;
    int a,b; cin >>a >>b;
    vector from(n, set<pii>());
    rep(i,0,m) {
        int u,v,w; cin >>u >>v >>w;
        from[u].insert({1e9,v});
        if(ed[u].count(v)) {
            min_self(ed[u][v],w);
        } else {
            ed[u][v] = w;
        }
    }
    vector larang(n, set<pii>());
    rep(i,0,k) {
        int x,y,z; cin >>x >>y >>z;
        larang[y].insert({x,z});
    }
    vector dp(n, map<int,int>());
    dp[a][a] = 0;
    priority_queue<ipii,vector<ipii>,greater<ipii>> pq;
    pq.push({0,{a,a}});
    int ans = 1e9;
    while(sz(pq)) {
        auto [d,ul] = pq.top(); pq.pop();
        auto [u, ls] = ul;
        if(dp[u][ls]<d) continue;
        if(u==b) {
            min_self(ans, d);
        }
        if(d>=ans) break;
        // debug() <<imie(u) imie(ls) imie(dp[u][ls]);
        auto it = from[u].upper_bound({d,1e9});
        vector<pii> ve;
        while(it!=from[u].end()) {
            auto [d_old, v] = *it;
            if(larang[u].count({ls,v})) {
                it++;
                continue;
            }
            ve.push_back(*it);
            dp[v][u] = d+ed[u][v];
            pq.push({dp[v][u],{v,u}});
            it++;
        }
        for(auto [d_old,v]: ve) {
            from[u].erase({d_old,v});
            from[u].insert({d,v});
        }
    }
    if(ans==1e9) {
        ans = -1;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}