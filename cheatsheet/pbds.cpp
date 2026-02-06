#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

#include<bits/extc++.h>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
oset<pii> s;

const int mxn=1e5;
int n;

void solve() {
    s.insert({1,-1});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}