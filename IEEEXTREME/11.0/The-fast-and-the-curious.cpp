#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
#define rep(i,from,to) for(int i = from; i < (to);i++)
typedef vector<int> vi; 

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;
bool flag[mxn];
vector<pii> edlist;

vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
    int me = num[at] = ++Time; int top=me;
    for(auto [y,e]: ed[at]) if(e != par) {
        if(num[y]) {
            top = min(top, num[y]);
            if(num[y]<me) {
                st.push_back(e);
            }
        } else {
            int si = sz(st);
            int up = dfs(y, e, f);
            top = min(top, up);
            if(up == me) {
                st.push_back(e);
                f(vi(st.begin()+si, st.end())); // call function
                st.resize(si);
            }
            else if(up<me) st.push_back(e);
            else {
                /* e is a bridge*/
            }
        }
    }
    return top;
}

template<class F>
void bicomps(F f) {
    num.assign(sz(ed), 0);
    rep(i,0,sz(ed)) if(!num[i]) dfs(i,-1,f);
}

void solve() {
    cin >>n >>m;
    ed.resize(n);
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        ed[u].push_back({v,sz(edlist)});
        ed[v].push_back({u,sz(edlist)});
        edlist.push_back({u,v});
    }
    bicomps([&](const vi& eids) -> void {
        for(auto eid : eids) {
            flag[edlist[eid].fi] = 1;
            flag[edlist[eid].se] = 1;
        }
    });
    for(int i=0;i<n;i++) {
        if(!flag[i]) {
            cout <<i+1 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}