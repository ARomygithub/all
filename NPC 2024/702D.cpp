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
ll d,k,a,b,t;

void solve() {
    cin >>d >>k >>a >>b >>t;
    ll ans = 1e18;
    ll ats = d/k;
    min_self(ans, d*a + (ats - (ats*k==d))*t);
    min_self(ans, d*b);
    if(k<=d) {
        min_self(ans, k*a + (d-k)*b);
        min_self(ans, k*ats*a + (d- k*ats)*b + (ats-1)*t);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}