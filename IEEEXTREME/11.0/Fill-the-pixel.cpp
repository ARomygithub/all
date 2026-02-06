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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
const int di1[4]={-1,0,1,0},dj1[4]={0,1,0,-1}, di2[4]={-1,1,1,-1},dj2[4]={1,1,-1,-1};
int r,c,t;
string s[mxn];

bool e(int i,  int j) {
    return i>=0&&i<r&&j>=0&&j<c;
}

void solve() {
    cin >>c >>r;
    for(int i=0;i<r;i++) {
        cin >>s[i];
    }
    vector<vector<bool>> vis1(r,vector<bool>(c,0));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            vis1[i][j] = (s[i][j]=='0');
        }
    }
    int ans1=0;
    function<void(int,int)> dfs1,dfs2,dfs3;
    dfs1 = [&](int i, int j) -> void {
        vis1[i][j] = 1;
        for(int k=0;k<4;k++) {
            int ii=i+di1[k],jj=j+dj1[k];
            if(e(ii,jj)&&!vis1[ii][jj]) {
                dfs1(ii,jj);
            }
        }
    };
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!vis1[i][j]) {
                ans1++;
                dfs1(i,j);
            }
        }
    }
    vector<vector<bool>> vis2(r,vector<bool>(c,0));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            vis2[i][j] = (s[i][j]=='0');
        }
    }
    int ans2=0;
    dfs2 = [&](int i, int j) -> void {
        vis2[i][j] = 1;
        for(int k=0;k<4;k++) {
            int ii=i+di2[k],jj=j+dj2[k];
            if(e(ii,jj)&&!vis2[ii][jj]) {
                dfs2(ii,jj);
            }
        }
    };
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!vis2[i][j]) {
                ans2++;
                dfs2(i,j);
            }
        }
    }
    vector<vector<bool>> vis3(r,vector<bool>(c,0));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            vis3[i][j] = (s[i][j]=='0');
        }
    }
    int ans3=0;
    dfs3 = [&](int i, int j) -> void {
        vis3[i][j] = 1;
        for(int k=0;k<4;k++) {
            int ii=i+di1[k],jj=j+dj1[k];
            if(e(ii,jj)&&!vis3[ii][jj]) {
                dfs3(ii,jj);
            }
        }
        for(int k=0;k<4;k++) {
            int ii=i+di2[k],jj=j+dj2[k];
            if(e(ii,jj)&&!vis3[ii][jj]) {
                dfs3(ii,jj);
            }
        }        
    };    
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!vis3[i][j]) {
                ans3++;
                dfs3(i,j);
            }
        }
    }
    cout <<ans1 <<" " <<ans2 <<" " <<ans3 <<"\n";
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