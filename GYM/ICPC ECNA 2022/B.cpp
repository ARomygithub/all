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

const int mxn=1e3;
int n,c;
int a[mxn];

void solve() {
    cin >>c >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector vis(c+1, vector(c+1,0));
    vis[0][0] = 1;
    rep(i,0,n) {
        per(j,c,-1) {
            per(k,c,-1) {
                if(vis[j][k]) {
                    if(j+a[i]<=c) {
                        vis[j+a[i]][k] = 1;
                    }
                    if(k+a[i]<=c) {
                        vis[j][k+a[i]] = 1;
                    }
                }
            }
        }
    }
    int ans = -1;
    int c1=-1,c2=-1;
    rep(i,0,c+1) {
        rep(j,0,c+1) {
            if(vis[i][j]) {
                if(ans< i+j) {
                    ans = i+j;
                    c1 = i;
                    c2 = j;
                } else if(ans==i+j) {
                    if(abs(c1-c2)>abs(i-j)) {
                        c1 = i;
                        c2 = j;
                    }
                }
            }
        }
    }
    if(c1<c2) swap(c1,c2);
    cout <<c1 <<" " <<c2 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}