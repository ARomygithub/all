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
int m;

ll C(int n, int k) {
    vector<int> ats,bwh;
    rep(i,0,k) {
        bwh.push_back(i+1);
        ats.push_back(n-i);
    }
    rep(i,0,sz(bwh)) {
        int j = 0;
        while(bwh[i]>1) {
            int d = __gcd(bwh[i],ats[j]);
            bwh[i] /=d;
            ats[j] /=d;
            j++;
        }
    }
    ll ans = 1;
    rep(i,0,sz(ats)) {
        ans = ans*ats[i];
    }
    return ans;  
}

void solve() {
    cin >>m;
    ll ans = C(m*2,m)-C(m*2,m-1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}