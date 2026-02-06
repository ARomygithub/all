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

const int mxn=1e5;
int n;
int a[mxn];

using ipii = pair<int,pii>;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    set<pii> s;
    rep(i,0,n-1) {
        s.insert({a[i]&a[i+1],i});
    }
    set<int> nd;
    rep(i,0,n) {
        nd.insert(i);
    }
    while(sz(s)) {
        auto it = --s.end();
        auto [val,i] = *it;
        ans += val;
        s.erase(it);
        auto it2 = nd.lower_bound(i);
        auto nx = it2; nx++;
        auto nx2 = nx; nx2++;
        if(nx2!=nd.end()) {
            s.erase({a[(*nx)]&a[(*nx2)],(*nx)});
        }
        auto pr = it2;
        bool adapr = 0;
        if(pr!=nd.begin()) {
            pr--;
            adapr = 1;
            s.erase({a[(*pr)]&a[i],(*pr)});
        }
        a[i] = val;
        if(adapr) {
            s.insert({a[(*pr)]&a[i],(*pr)});
        }
        if(nx2!=nd.end()) {
            s.insert({a[i]&a[(*nx2)],i});
        }
        nd.erase(nx);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}