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

const int mxn=2e5;
int n,t;

void slv(vi& v, int x) {
    v.push_back(2);
    rep(i,4,x-1) {
        v.push_back(i);
    }
    v.push_back(3);
    v.push_back(1);
    v.push_back(x-1);
    v.push_back(x);
}

void solve() {
    cin >>n;
    if(n==6) {
        cout <<"7\n";
        cout <<"1 2 4 6 5 3\n";
        return;
    }
    vi ans;
    if(n%2) {
        cout <<n <<"\n";
        slv(ans, n);
    } else {
        int m = 1;
        while(m <n) {
            m = m*2+1;
        }
        cout <<m <<"\n";
        int p2 = m - (m/2);
        rep(i,p2+1,n+1) {
            ans.push_back(i);
        }
        slv(ans, m/2);
        ans.push_back(p2);
    }
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
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