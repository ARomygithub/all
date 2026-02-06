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
int n,m;

void solve() {
    cin >>n >>m;
    vi v(n);
    rep(i,0,n) {
        cin >>v[i];
    }
    multiset<int> hx;
    rep(i,0,m) {
        int x1,x2,y; cin >>x1 >>x2 >>y;
        if(x1==1) {
            hx.insert(x2);
        }
    }
    int ans = n+m;
    v.push_back(1e9);
    sort(all(v));
    rep(i,0,sz(v)) {
        while(sz(hx) && (*hx.begin())<v[i]) {
            hx.erase(hx.begin());
        }
        min_self(ans, i+sz(hx));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}