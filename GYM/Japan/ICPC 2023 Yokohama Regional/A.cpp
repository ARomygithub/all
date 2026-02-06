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

const int mxn=10;
const int di[4]={-1,0,1,0}, dj[4]={0,1,0,-1};
const string yk = "YOKOHAMA";
int n,m;
string s[mxn];
int ans = 0;

bool e(pii u) {
    return u.fi>=0&&u.fi<n&&u.se>=0&&u.se<m;
}

void dfs(pii u, int pos) {
    if(pos==7) {
        ans++;
        return;
    }
    rep(k,0,4) {
        pii v = {u.fi+di[k],u.se+dj[k]};
        if(e(v) && s[v.fi][v.se]==yk[pos+1]) {
            dfs(v, pos+1);
        }
    }
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='Y') {
                dfs({i,j},0);
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}