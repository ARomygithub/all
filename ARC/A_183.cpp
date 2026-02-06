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
int n,k;

void solve() {
    cin >>n >>k;
    vi ans;
    if(n%2) {
        rep(i,0,k) {
            ans.push_back((n+1)/2);
        }
        if(n>1) {
            int mn1 = (n+1)/2 -1;
            ans.push_back(mn1);
            vi ct(n+1,k);
            ct[mn1]--;
            ct[mn1+1] = 0;
            per(i,n,0) {
                rep(j,0,ct[i]) {
                    ans.push_back(i);
                }
            }
        }
    } else {
        ans.push_back(n/2);
        vi ct(n+1,k);
        ct[n/2]--;
        per(i,n,0) {
            rep(j,0,ct[i]) {
                ans.push_back(i);
            }
        }
    }
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}