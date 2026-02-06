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

void solve() {
    vector odd(2, vector<int>());
    vector even(2, vector<int>());
    cin >>n;
    rep(i,0,n) {
        int x,y; cin >>x >>y;
        if((x+y)%2) {
            odd[0].push_back(x-y);
            odd[1].push_back(x+y);
        } else {
            even[0].push_back(x-y);
            even[1].push_back(x+y);
        }
    }
    ll ans = 0;
    rep(i,0,2) {
        sort(odd[i].begin(), odd[i].end());
        ll temp = 0;
        rep(j,0,sz(odd[i])) {
            temp += 1ll*odd[i][j]*(j-(sz(odd[i]) -j-1));
        }
        temp /=2;
        ans += temp;
    }
    rep(i,0,2) {
        sort(even[i].begin(), even[i].end());
        ll temp = 0;
        rep(j,0,sz(even[i])) {
            temp += 1ll*even[i][j]*(j-(sz(even[i]) -j-1));
        }
        temp /=2;
        ans += temp;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}