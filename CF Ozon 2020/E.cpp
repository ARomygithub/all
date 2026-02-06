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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e3;
int n,m;

void solve() {
    cin >>n >>m;
    vector<int> ans(n);
    vector<int> ct(n,0);
    int k = -1;
    rep(i,0,n) {
        if(i+1<n) {
            ct[i+1] = ct[i] + (i+1)/2;
        }
    }
    rep(i,0,n) {
        if(ct[i]>m) {
            k = i;
            ans[i] = k*2+1 - 2*(m-ct[i-1]);
            rep(j,i+1,n) {
                ans[j] = (k+2)*(j-i+2) + 1;
            } 
            // cout <<"TEs\n";
            break;
        } else {
            ans[i] = i+1;
        }
    }
    if(ct[n-1]<m) {
        cout <<"-1\n";
    } else {
        rep(i,0,n) {
            cout <<ans[i] <<" \n"[i==n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}