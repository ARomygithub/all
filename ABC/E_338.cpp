#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int mxn=2e5;
int n;
pii v[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>v[i].fi >>v[i].se;
    }
    vector<int> pos(n*2+1,0);
    vector<oset<int>> vs(1);
    rep(i,1,n*2+1) {
        vs[0].insert(i);
    }
    rep(j,0,n) {
        if(pos[v[j].fi]!=pos[v[j].se]) {
            cout <<"Yes\n";
            return;
        }
        int posi = pos[v[j].fi];
        vs[posi].erase(v[j].fi);
        vs[posi].erase(v[j].se);
        int id = sz(vs);
        int l = vs[posi].order_of_key(min(v[j].fi,v[j].se));
        int r = vs[posi].order_of_key(max(v[j].fi,v[j].se));
        oset<int> temps;
        if((r-l)<=sz(vs[posi])) {
            rep(i,l,r) {
                auto it = *vs[posi].find_by_order(i);
                temps.insert(it);
            }
        } else {
            rep(i,r,sz(vs[posi])) {
                auto it = *vs[posi].find_by_order(i);
                temps.insert(it);
            }
            rep(i,0,l) {
                auto it = *vs[posi].find_by_order(i);
                temps.insert(it);
            }
        }
        if(sz(temps)>0) {
            for(auto ti : temps) {
                pos[ti] = id;
                vs[posi].erase(ti);
            }
            vs.push_back(temps);
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

