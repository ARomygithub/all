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

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int mxn=1e5;
int n;
ll l;
int b[mxn];
Tree<pll> oset;

void solve() {
    cin >>n >>l;
    rep(i,0,n) {
        cin >>b[i]; b[i]--;
    }
    oset.insert({1ll,l});
    rep(i,0,n) {
        auto it = oset.find_by_order(b[i]);
        auto [le,ri] = *it;
        oset.erase(it);
        ll mid = (le+ri)/2;
        oset.insert({le,mid});
        oset.insert({mid+1,ri});
    }
    vector<ll> ans;
    for(auto [le,ri]: oset) {
        ans.push_back(ri-le+1);
    }
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}