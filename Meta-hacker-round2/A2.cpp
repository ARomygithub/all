#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<bool,int> pbi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e3;
const int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int n,m,t;
string s[mxn];
bool vis[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&!vis[i][j];
}

pbi cek(int i, int j) {
    bool ret=1;
    int ct=1;
    vis[i][j] = 1;
    for(int k=0;k<4;k++) {
        int ii=i+di[k],jj=j+dj[k];
        if(e(ii,jj)) {
            if(s[ii][jj]=='.') {
                ret = 0;
                // return ret;
            } else if(s[ii][jj]=='W') {
                auto [flag, cti] = cek(ii,jj);
                ret &= flag;
                ct +=cti;
            }
        }
    }
    return make_pair(ret,ct);
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>s[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            vis[i][j] = 0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]=='.') {
                int temp=0;
                s[i][j] = 'B';
                for(int k=0;k<4;k++) {
                    int ii=i+di[k],jj=j+dj[k];
                    if(e(ii,jj)&&s[ii][jj]=='W') {
                        auto [tes,ct] = cek(ii,jj);
                        if(tes) {
                            // cout <<i <<" " <<j <<"\n";
                            temp +=ct;
                        }
                    }
                }
                s[i][j] = '.';
                max_self(ans,temp);
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
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
        cout <<flush;
    }
}