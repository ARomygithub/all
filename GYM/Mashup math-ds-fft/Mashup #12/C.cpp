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
int n,m,k,t;
int h[mxn];

vi topoSort(const vector<vi>& gr, vi& indeg) {
    vi ret;
    for (auto& li : gr) for (int x : li) indeg[x]++;
    queue<int> q; // use priority_queue for lexic. largest ans.
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for (int x : gr[i])
            if (--indeg[x] == 0) q.push(x);
    }
    return ret;
}

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>h[i];
    }
    vector gr(n, vi());
    vi indeg(n,0);
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        gr[u].push_back(v);
    }
    auto topo = topoSort(gr, indeg);
    vector<ll> len(n,0);
    auto ds = [&](int x, int y) -> ll {
        if(x<=y) return y-x;
        return 1ll*(k-x)+y;
    };
    for(auto u : topo) {
        for(auto v: gr[u]) {
            max_self(len[v], len[u]+ds(h[u],h[v]));
        }
    }
    set<pll> s;
    multiset<ll> sv;
    rep(i,0,n) {
        if(sz(gr[i])==0) {
            ll awl = (((1ll*h[i] - len[i])%k) + k)%k;
            s.insert({awl,len[i]+awl});
            sv.insert(len[i]+awl);
        }
    }
    auto it = s.begin();
    ll ans = 1e18;
    while(it!=s.end()) {
        ll tmp = *(--sv.end());
        tmp -= (*it).fi;
        min_self(ans, tmp);
        sv.insert((*it).se+k);
        it++;
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