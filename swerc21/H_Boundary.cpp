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
int n,m,t;

void solve() {
    cin >>n >>m;
    set<int> s;
    s.insert(1);

    int d = __gcd(n,m-2);
    auto slv_d = [&]() -> void {
        for(int i=1;i*i<=d;i++) {
            if((d%i)==0) {
                s.insert(i);
                s.insert(d/i);
            }
        }
    };
    slv_d();
    d = __gcd(n-1,m-1);
    slv_d();
    d = __gcd(n-2,m);
    slv_d();
    if((n%2)==0 || (m%2)==0) {
        s.insert(2);
    }
    cout <<sz(s) <<" ";
    auto it = s.begin();
    rep(i,0,sz(s)) {
        cout <<(*it) <<" \n"[i==sz(s)-1];
        it++;
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