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

void solve() {
    cin >>n;
    if(n%2) {
        cout <<"YES\n";
        vi ans(n*2,-1);
        rep(i,0,n) {
            if(i%2) {
                ans[i+n] = i*2+1;
                ans[i] = i*2+2;
            } else {
                ans[i] = i*2+1;
                ans[i+n] = i*2+2;
            }
        }
        rep(i,0,n*2) {
            cout <<ans[i] <<" \n"[i==n*2-1];
        }
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}