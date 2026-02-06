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
char c[3];
int ct[3];

void solve() {
    rep(i,0,3) {
        cin >>c[i];
    }
    vector<pii> v = {{0,1},{0,2},{1,2}};
    rep(i,0,3) {
        if(c[i]=='<') {
            ct[v[i].se]++;
        } else {
            ct[v[i].fi]++;
        }
    }
    rep(i,0,3) {
        if(ct[i]==1) {
            cout <<(char)(i+'A') <<"\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}