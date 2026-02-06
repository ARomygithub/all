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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
const int di[4]={-1,0,1,0}, dj[4]={0,-1,0,1};
int n,m,y;
int a[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}

void solve() {
    cin >>n >>m >>y;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>a[i][j];
        }
    }
    vector vis(n, vector<bool>(m, 0));
    set<ipii> s;
    int ans = n*m;
    rep(i,0,n) {
        s.insert({a[i][0],{i,0}});
        s.insert({a[i][m-1],{i,m-1}});
    }
    rep(j,0,m) {
        s.insert({a[0][j], {0,j}});
        s.insert({a[n-1][j], {n-1,j}});
    }
    rep(i,1,y+1) {
        while(sz(s) && (*s.begin()).fi<=i) {
            auto [val, pq] = *s.begin(); s.erase(s.begin());
            auto [p,q] = pq;
            vis[p][q] = 1;
            ans--;
            rep(k,0,4) {
                int ii = p+di[k], jj=q+dj[k];
                if(e(ii,jj)&&!vis[ii][jj]) {
                    s.insert({a[ii][jj], {ii,jj}});
                }
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}