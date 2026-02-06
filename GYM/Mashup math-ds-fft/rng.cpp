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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    n = 6;
    vector<string> vs;
    rep(i,0,n) {
        // if(i>=2) {
        //     vs.push_back("new");
        //     continue;
        // }
        // if(i==4) {
        //     vs.push_back("new");
        //     continue;
        // }
        // if(rng()%2) {
        //     vs.push_back("new");
        // } else {
        //     vs.push_back("old");
        // }
        cout <<(rng()%4) <<", ";
    }
    // cout <<"[ ";
    // rep(i,0,sz(vs))  {
    //     cout <<vs[i] <<", ";
    // }
    // cout <<"]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}