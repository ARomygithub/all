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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=16;
int n,m;
vector<pii> adj[mxn];
int val[mxn];
bool vis[mxn];
vector<pii> v_temp;

void dfs(int u) {
    vis[u] = 1;
    v_temp.push_back({val[u],u});
    for(auto [w,v]: adj[u]) {
        if(!vis[v]) {
            val[v] = val[u]+w;
            dfs(v);
        }
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        int ai,bi,c; cin >>ai >>bi >>c; ai--,bi--;
        adj[bi].push_back({c,ai});
        adj[ai].push_back({c*-1,bi});
    }
    vector<int> pola;
    vector<vector<int>> b;
    rep(i,0,n) {
        if(!vis[i]) {
            v_temp.clear();
            dfs(i);
            sort(v_temp.begin(),v_temp.end());
            int poli = 1;
            int lsbit = 0;
            vector<int> bi;
            bi.push_back(v_temp[0].se);
            rep(j,1,sz(v_temp)) {
                int diff = v_temp[j].fi - v_temp[j-1].fi;
                lsbit += diff;
                bi.push_back(v_temp[j].se);
                poli += 1<<lsbit;
            }
            pola.push_back(poli);
            b.push_back(bi);
        }
    }
    set<int> vld;
    vector<vector<int>> v(1<<n);
    vector<set<int>> same(1<<n);
    vld.insert(0);
    rep(i,0,sz(pola)) {
        int poli = pola[i];
        set<int> vld_new;
        vector<vi> v_new(1<<n);
        vector<set<int>> same_new(1<<n);
        for(auto st : vld) {
            rep(j,0,n) {
                int poli2 = poli<<j;
                if((st+poli2 == (st^poli2)) && st+poli2<(1<<n)) {
                    int poli3 = st+poli2;
                    vector<int> v3(v[st]);
                    set<int> same3(same[st]);
                    v3.push_back(j);
                    same3.insert(i);
                    if(vld_new.count(poli3)) {
                        set<int> er;
                        for(auto k: same_new[poli3]) {
                            if(!(v_new[poli3][k]==v3[k] && same3.count(k))) {
                                er.insert(k);
                            }
                        }
                        for(auto eri: er) {
                            same_new[poli3].erase(eri);
                        }
                    } else {
                        vld_new.insert(poli3);
                        v_new[poli3].swap(v3);
                        same_new[poli3].swap(same3);
                    }
                }
            }
        }
        vld.swap(vld_new);
        v.swap(v_new);
        same.swap(same_new);
    }
    vector<int> ans(n, -1);
    if(vld.count((1<<n)-1)) {
        auto& v3 = v[(1<<n)-1];
        auto& same3 = same[(1<<n)-1];
        for(int i : same3) {
            int vali = v3[i];
            int idx = 0;
            rep(j,0,n) {
                if((pola[i]>>j)&1) {
                    ans[b[i][idx]] = vali+j+1;
                    idx++;
                }
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}