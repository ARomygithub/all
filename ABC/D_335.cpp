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

const int mxn=45;
int n;
int ans[mxn][mxn];

void solve() {
    cin >>n;
    int ct=1;
    rep(i,0,n/2) {
        int x=i,y=i;
        do {
            ans[x][y] = ct++;
            y++;
        } while(y!=n-i);
        y--;
        do {
            x++;
            ans[x][y] = ct++;
        } while(x!=n-1-i);
        do {
            y--;
            ans[x][y] = ct++;
        } while(y!=i);
        do {
            x--;
            ans[x][y] = ct++;
        } while(x!=i+1);
    }
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==n/2 && j==n/2) {
                cout <<"T ";
            } else {
                cout <<ans[i][j] <<" \n"[j==n-1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}