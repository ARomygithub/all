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
#define pb push_back
typedef pair<pii,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5,mxa=6e5+1;
int n,q;
int phi[mxa];

// https://codeforces.com/contest/342/submission/90349180
struct centroid {
  vector<vector<int> > edges;
  vector<bool> vis;
  vector<int> par;
  vector<int> szi;
  vector<int> ans;
  vector<stack<pipi>> lazy;
  int n;
  int ctk=0;
 
  void init(int s) {
    n = s;
    edges = vector<vector<int> >(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    szi = vector<int>(n);
    ans = vector<int>(n,0);
    lazy = vector<stack<pipi>>(n);
  }
 
  void edge(int a, int b) {
    edges[a].pb(b);
    edges[b].pb(a);
  }
 
  int find_size(int v, int p = -1) {
    if (vis[v]) return 0;
    szi[v] = 1;
 
    for (int x: edges[v]) {
      if (x != p) {
        szi[v] += find_size(x, v);
      }
    }
 
    return szi[v];
  }
 
  int find_centroid(int v, int p, int n) {
    for (int x: edges[v]) {
      if (x != p) {
        if (!vis[x] && szi[x] > n / 2) {
          return find_centroid(x, v, n);
        }
      }
    }
 
    return v;
  }
 
  void init_centroid(int v = 0, int p = -1) {
    find_size(v);
    
    if(p==-1) {
        int c = find_centroid(v, -1, szi[v]);
        vis[c] = true;
        par[c] = p;
        for (int x: edges[c]) {
            if (x!=p) {
                init_centroid(x, c);
            }
        }
    } else {
        par[v] = p;
        for(int x : edges[v]) {
            if(x!=p) {
                init_centroid(x,v);
            }
        }
    }
  }

  void app(int u, int id, int l, int len, int last) {
    ans[u] = l;
    if(len==0) return;
    stack<pipi> reversedSt;
    while(sz(lazy[u]) && lazy[u].top().fi.fi<len) {
        reversedSt.push(lazy[u].top());
        lazy[u].pop();
    }
    if(sz(lazy[u])) {
        if(lazy[u].top().se.fi<id) {
            if(lazy[u].top().fi.fi==len) {
                lazy[u].pop();
            }
            lazy[u].push({{len,l},{id,last}});            
        }
    } else {
        lazy[u].push({{len,l},{id,last}});
    }
    while(sz(reversedSt)) {
        auto [rlenl, ridlast] = reversedSt.top(); reversedSt.pop();
        auto [rlen, rl] = rlenl;
        auto [rid, rlast] = ridlast;
        if(sz(lazy[u])) {
            if(rid>lazy[u].top().se.fi) {
                lazy[u].push({{rlen,rl},{rid,rlast}});                
            }
        } else {
            lazy[u].push({{rlen,rl},{rid,rlast}});
        }
    }
  }

  void update(int v, int l, int r) {
    int id = ++ctk;
    int len = r-l;
    // id,l,len,p
    int last=-1;
    while(true) {
        // debug() <<imie(v) <<imie(id) <<imie(l) <<imie(len) <<imie(last);
        app(v, id, l, len, last);
        if(len==0) break;
        len--;
        l++;
        last = v;
        if(par[v]==-1) break;
        v = par[v];
    }
  }

    void appLazy(int u) {
        stack<pipi> reversedSt;
        // debug() <<imie(u);
        while(sz(lazy[u])) {
            reversedSt.push(lazy[u].top());
            // debug() <<imie(lazy[u].top());
            lazy[u].pop();
        }
        while(sz(reversedSt)) {
            auto [lenl,idlast] = reversedSt.top(); reversedSt.pop();
            auto [len, l] = lenl;
            auto [id,last] = idlast;
            len--, l++;
            for(int v: edges[u]) {
                if(v==last) continue;
                if(v==par[u]) continue;
                // debug() <<imie(v);
                app(v,id,l,len,last);
            }
        }
    }

    void calc_top(int u, int p) {
        // debug() <<imie(u) <<imie(p);
        if(p!=-1) {
            calc_top(p,par[p]);
            appLazy(p);
        }
    }

  int qry(int v) {
    calc_top(v,par[v]);
    return ans[v];
  }
} ct;

void solve() {
    cin >>n;
    ct.init(n);
    rep(i,1,n) {
        int u,v; cin >>u >>v; u--,v--;
        if(u>v) swap(u,v);
        ct.edge(u,v);
    }
    cin >>q;
    // centroid
    ct.init_centroid();
    // debug() <<imie(ct.par);
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int v,l,r; cin >>v >>l >>r; v--;
            ct.update(v,l,r);
        } else {
            int v; cin >>v; v--;
            cout <<phi[ct.qry(v)] <<"\n";
        }
    }
}

void init_phi() {
	rep(i,0,mxa) phi[i] = i&1 ? i : i/2;
	for (int i = 3; i < mxa; i += 2) if(phi[i] == i)
		for (int j = i; j < mxa; j += i) phi[j] -= phi[j] / i;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_phi();
    solve();
}