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

const int mxn=1e5;
ll n;
map<ll,ll> mp;

ll get_ans(ll u) {
    if(u==1) {
        mp[u] = 0;
        return 0;
    }
    if(mp.count(u)) {
        return mp[u];
    } else {
        mp[u] = get_ans(u/2) + get_ans((u+1)/2) + u;
        return mp[u];
    }
}

void solve() {
    cin >>n;
    cout <<get_ans(n) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}