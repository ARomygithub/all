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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
int n,m;
pii lr[mxn];
set<int> adj[mxn];
bool act[mxn], vis[mxn];

void dfs(int u) {
    act[u] = 1;
    vis[u] = 1;
    vector<int> s;
    for(int v: adj[u]) {
        if(act[v]) {
            cout <<"-1\n";
            exit(0);
        } else if(!vis[v]) {
            dfs(v);
        }
        max_self(lr[v].se, lr[u].se+1);
        if(lr[v].fi<lr[v].se) {
            cout <<"-1\n";
            exit(0);
        }
        s.push_back(lr[v].fi);
    }
    sort(s.begin(),s.end());
    int last = 1e9;
    per(i,sz(s)-1,-1) {
        int sni = s[i];
        min_self(last,sni);
        last--;
    }
    min_self(lr[u].fi, last);
    if(lr[u].fi<lr[u].se) {
        cout <<"-1\n";
        exit(0);
    }
    act[u] = 0;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>lr[i].se >>lr[i].fi;
        lr[i].fi--, lr[i].se--;
    }
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].insert(v);
    }
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    vector<piii> v;
    rep(i,0,n) {
        v.push_back({lr[i],i});
    }
    sort(v.begin(),v.end());
    vector<int> ans(n,-1);
    set<pii> pos;
    pos.insert({0,n-1});
    rep(i,0,sz(v)) {
        // if(sz(pos)==0) {
        //     cout <<"-1\n";
        //     return;
        // }
        auto it = pos.upper_bound({v[i].fi.se,(int)(1e9)});
        int l=-1,r=-1;
        if(it==pos.begin()) {
            // debug() <<imie("begin");
            // debug() <<imie(*it);
            l = (*it).fi;
            r = (*it).se;
        } else {
            if(it!=pos.end()) {
                // debug() <<imie("bukan end");
                // debug() <<imie(*it);
                l = (*it).fi;
                r = (*it).se;
            }
            it--;
            // debug() <<imie("setelah min");
            // debug() <<imie(*it);
            if(it->se >=v[i].fi.se) {
                // debug() <<imie("masuk");
                l = (*it).fi;
                r = (*it).se;
            }
        }
        int now = max(v[i].fi.se,l);
        if(now<=r && now<=v[i].fi.fi) {
            ans[now] = v[i].se;
            pos.erase({l,r});
            // debug() <<imie(now);
            // debug() <<imie(v[i].fi);
            // debug() <<imie(l) <<imie(r);
            // if(sz(pos)) {
            //     for(auto posi: pos) {
            //         debug() <<imie(posi);
            //     } 
            // }
            if(l<=now-1) {
                // debug() <<imie(l) <<imie(now-1);
                pos.insert({l,now-1});
            }
            if(r>=now+1) {
                // debug() <<imie(now+1) <<imie(r);
                pos.insert({now+1,r});
            }
        } else {
            cout <<"-1\n";
            return;
        }
    }
    rep(i,0,n) {
        cout <<ans[i]+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}