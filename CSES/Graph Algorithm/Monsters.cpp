#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e3, di[4]={1,0,-1,0}, dj[4]={0,1,0,-1};
const char dc[4]={'D','R','U','L'};
int n,m,si, sj, d1[mxn][mxn], d2[mxn][mxn], p1[mxn][mxn], p2[mxn][mxn];
string s[mxn];
bool vis[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.'&&!vis[i][j];
}

void bfs(vector<ar<int,2>> v1, int d[mxn][mxn], int p[mxn][mxn]) {
    queue<ar<int,2>> qu;
    memset(vis,0,sizeof(vis));
    memset(d, 1e4, sizeof(d1));
    for(ar<int,2> a: v1) {
        qu.push(a);
        vis[a[0]][a[1]]=1;
        d[a[0]][a[1]]=1;
    }
    while(qu.size()) {
        ar<int,2> u=qu.front(); qu.pop();
        for(int k=0;k<4;k++) {
            int ni=u[0]+di[k], nj=u[1]+dj[k];
            if(!e(ni,nj))
                continue;
            qu.push({ni,nj});
            vis[ni][nj]=1;
            d[ni][nj]=d[u[0]][u[1]]+1;
            p[ni][nj]=k;
        }
    }
}

int main() {
    cin >>n >>m;
    vector<ar<int,2>> v2;
    for(int i=0;i<n;i++) {
        cin >>s[i];
        for(int j=0;j<m;j++) {
            if(s[i][j]=='A')
                si=i, sj=j, s[i][j]='.';
            if(s[i][j]=='M')
                v2.push_back({i,j}), s[i][j]='.';
        }
    }
    bfs({{si, sj}}, d1, p1);
    bfs(v2, d2, p2);
    int ti=-1, tj;
    for(int i=0;i<n;i++) {
        if(d1[i][0]<d2[i][0])
            ti=i,tj=0;
        if(d1[i][m-1]<d2[i][m-1])
            ti=i, tj=m-1;
    }
    for(int j=0;j<m;j++) {
        if(d1[0][j]<d2[0][j])
            ti=0, tj=j;
        if(d1[n-1][j]<d2[n-1][j])
            ti=n-1, tj=j;
    }
    if(~ti) {
        cout <<"YES\n";
        string t;
        while(ti^si||tj^sj) {
            t+=dc[p1[ti][tj]];
            int dd= p1[ti][tj]^2;
            ti+=di[dd];
            tj+=dj[dd];
        }
        reverse(t.begin(),t.end());
        cout <<t.size() <<"\n";
        cout <<t;
    }
    else {
        cout <<"NO";
    }
}