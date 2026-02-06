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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

const int mxn=5e5;
int q,t;

void solve() {
    cin >>q;
    int szi=1;
    vector adj(1, vector<int>());
    vector add(1, vector<pii>());
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int v; cin >>v; v--;
            adj.push_back(vector<int>());
            add.push_back(vector<pii>());
            adj[v].push_back(szi);
            szi++;
        } else {
            int v,x; cin >>v >>x; v--;
            add[v].push_back({szi,x});
        }
    }
    FT ft(szi);
    vector<ll> ans(szi,0);
    function<void(int)> dfs;
    dfs = [&](int u) -> void {
        for(auto [ex,x]: add[u]) {
            ft.update(ex-1,x);
        }
        ans[u] = ft.query(szi)-ft.query(u);
        for(auto v: adj[u]) {
            dfs(v);
        }
        for(auto [ex,x]: add[u]) {
            ft.update(ex-1,x*-1);
        }
    };
    dfs(0);
    rep(i,0,szi) {
        cout <<ans[i] <<" \n"[i==szi-1];
    }
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