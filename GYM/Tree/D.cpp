#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int mxn=1e5,mxv=1<<18;
int n,t;

struct UF {
    ll ans = 0;
    vi e, dist;
    int ct = 0;
    vector<bool> flag;
    UF(int n) : e(n, -1), dist(n, 1e9), flag(n,0) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        if(flag[pa] && flag[pb]) {
            ans += dist[a]+dist[b]+1;
            ct++;
        } else {
            dist[b] = dist[a]+1;
        }
        if (e[pa] > e[pb]) swap(pa, pb);
        e[pa] += e[pb]; e[pb] = pa;
        flag[pa] = flag[pa]||flag[pb];
        return true;
    }
};
using piii = pair<int,pii>;

void solve() {
    // clock_t st = clock(); 
    cin >>n;
    set<int> sa;
    rep(i,0,n) {
        int ai; cin >>ai;
        sa.insert(ai);
    }
    UF uf(mxv);
    queue<int> q;
    for(auto ai : sa) {
        uf.flag[ai] = 1;
        uf.dist[ai] = 0;
        q.push(ai);
    }
    vector<piii> vpq;
    while(sz(q)) {
        auto ai = q.front(); q.pop();
        rep(j,0,18) {
            int bi = ai^(1<<j);
            if(uf.flag[uf.find(ai)] && uf.flag[uf.find(bi)]) {
                vpq.push_back({uf.dist[ai]+uf.dist[bi]+1,{ai,bi}});
            } else if(uf.join(ai,ai^(1<<j))) {
                q.push(bi);
            }
        }
    }
    // clock_t cur = clock() - st;
    // cout << fixed <<setprecision(5) << (double) cur/ CLOCKS_PER_SEC <<endl;

    // clock_t st2 = clock();
    // sort(all(vpq));
    rep(i,0,sz(vpq)) {
        auto [d,ab] = vpq[i];
        auto [ai,bi] = ab;
        uf.join(ai,bi);
        if(uf.ct==sz(sa)-1) break;
    }
    // clock_t cur2 = clock() - st2;
    // cout << fixed <<setprecision(5) << (double) cur2/ CLOCKS_PER_SEC <<endl;
    cout <<uf.ans <<"\n";
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