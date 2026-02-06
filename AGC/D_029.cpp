#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i= a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); --i)
#define sz(x) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A, B);
}

template<typename T>
void max_self(T& A, T B) {
    A = max(A, B);
}

const int mxn = 2e5;
int n,m, k;
set<int> obs[mxn];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,k) {
        int x,y; cin >>x >>y; x--,y--;
        obs[x].insert(y);
    }
    pii lr = {0,0};
    rep(i,1,n) {
        auto it = 
    }
    if(n==1) {
        cout <<"2\n";
    } else {
        cout <<(n-1)*2+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}