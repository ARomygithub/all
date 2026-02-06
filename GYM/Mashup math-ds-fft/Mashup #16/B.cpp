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

const int mxn=3e3;
int n,t;
string s[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    int ans = 0;
    vector le(n, vi(n,0)), ri(n, vi(n,0));
    rep(i,0,n) {
        int cur = 0;
        rep(j,0,n) {
            cur += le[i][j]+ri[i][j];
            if((cur + (s[i][j]-'0'))%2) {
                ans++;
                if(i+1<n) {
                    le[i+1][max(0,j-1)] += 1;
                    if(j+2<n) {
                        ri[i+1][j+2] -= 1;
                    }
                }
            }
            if(i+1<n) {
                if(le[i][j]!=0) {
                    le[i+1][max(0,j-1)] += le[i][j];
                }
                if(ri[i][j]!=0 && j+1<n) {
                    ri[i+1][j+1] += ri[i][j];
                }
            }
        }
    }
    cout <<ans <<"\n";
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