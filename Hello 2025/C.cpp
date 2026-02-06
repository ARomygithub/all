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
int l,r,t;

void solve() {
    cin >>l >>r;
    per(j,29,-1) {
        int cl = (l>>j)&1;
        int cr = (r>>j)&1;
        if(cl!=cr) {
            int x = r/(1<<j);
            x *= (1<<j);
            int y = x-1;
            rep(z,l,r+1) {
                if(z!=x && z!=y) {
                    cout <<x <<" " <<y <<" " <<z <<"\n";
                    return;
                }
            }
        }
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