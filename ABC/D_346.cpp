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

const int mxn=2e5;
int n;
string s;
ll c[mxn];

void solve() {
    cin >>n;
    cin >>s;
    rep(i,0,n) {
        cin >>c[i];
    }
    vector p(n, vector<ll>(2,0));
    rep(i,0,n) {
        p[i][0] = i>0?p[i-1][1]:0ll;
        p[i][1] = i>0?p[i-1][0]:0ll;
        if(s[i]=='1') {
            p[i][0] += c[i];
        } else {
            p[i][1] += c[i];
        }
    }
    ll ans = 1e18;
    rep(i,0,n-1) {
        rep(j,0,2) {
            ll temp = p[i][j];
            int jn = ((n-1-i)%2==1?j:(j^1));
            temp += p[n-1][jn]-p[i][j^1];
            min_self(ans,temp);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}