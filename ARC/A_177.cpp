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

const int mxn=10;
const int val[6] = {1,5,10,50,100,500};
int n;
int ct[6];
int x[mxn];

void solve() {
    rep(i,0,6) {
        cin >>ct[i];
    }
    cin >>n;
    rep(i,0,n) {
        cin >>x[i];
    }
    rep(i,0,n) {
        per(j,5,-1) {
            int temp = min(x[i]/val[j], ct[j]);
            x[i] -= temp*val[j];
            ct[j] -= temp;
        }
        if(x[i]>0) {
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}