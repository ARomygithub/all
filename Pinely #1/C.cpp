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

const int mxn=1e2;
int n,t;
string b[mxn];

// bool same(set<int>& s1, set<int>& s2) {
//     if(sz(s1)!=sz(s2)) return false;
//     auto it1 = s1.begin(), it2=s2.begin();
//     while(it1!=s1.begin()) {
//         if((*it1)!=(*it2)) return false;
//         it1++; it2++;
//     }
//     return true;
// }

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<set<int>> s(n), sin(n), sout(n);
    vector<bool> vis(n,0);
    rep(i,0,n) {
        rep(j,0,n) {
            if(b[i][j]=='1') {
                sout[i].insert(j);
                sin[j].insert(i);
            }
        }
    }
    int id = 1;
    function<void(int)> dfs;
    dfs = [&](int u) -> void {
        int mx = 0;
        for(auto v: sin[u]) {
            if(!vis[v]) {
                dfs(v);
            }
            max_self(mx, sz(s[v]));
        }
        vis[u] = 1;
        bool add = 0;
        if(sz(s[u])==0 || sz(s[u])==mx) {
            add = 1;
        } else {
            rep(v,0,n) {
                if(u==v || sin[u].count(v) || sout[u].count(v)) {
                    continue;
                }
                if(add) {
                    break;
                }
                bool super = 1;
                for(auto sui : s[u]) {
                    if(!s[v].count(sui)) {
                        super = 0;
                        break;
                    }
                }
                if(super) {
                    // if(!(same(sin[u],sin[v]) && same(sout[u],sout[v]))) {
                    //     add = 1;
                    // } else {
                    //     for(auto svi: s[v]) {
                    //         s[u].insert(svi);
                    //     }
                    // }
                    add = 1;
                }
            }
        }
        if(add) {
            s[u].insert(id); id++;
        }
        for(auto v: sout[u]) {
            for(auto sui: s[u]) {
                s[v].insert(sui);
            }
        }
    };
    rep(i,0,n) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    rep(i,0,n) {
        cout <<sz(s[i]) <<" ";
        for(auto it = s[i].begin(); it!=s[i].end();it++) {
            auto it2 = it; it2++;
            cout <<(*it) <<" \n"[it2==s[i].end()];
        }
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