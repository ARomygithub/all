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

const int mxn=1e3;
int n,k,a;
pii ts[mxn];

void solve() {
    cin >>n >>k >>a;
    rep(i,0,n) {
        cin >>ts[i].fi >>ts[i].se;
    }
    k /=a;
    int ans = k*200;
    rep(i,0,n) {
        int temp = (k-1)/ts[i].fi;
        int sisa = k - (temp*ts[i].fi);
        min_self(ans, temp*(ts[i].fi+ts[i].se)+sisa);
    } 
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}