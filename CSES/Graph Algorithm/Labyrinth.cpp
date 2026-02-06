#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e3, Di[4]={1, 0, -1, 0}, Dj[4]={0, 1, 0, -1};
int n, m, si, sj, ti, tj;
char Dc[4]={'D', 'R', 'U', 'L'};
string s[mxn], p[mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.';
}

int main() {
    cin >>n >>m;
    for(int i=0; i<n; i++) {
        cin >>s[i];
        for(int j=0; j<m; j++) {
            if(s[i][j]=='A')
                si=i, sj=j;
            if(s[i][j]=='B')
                ti=i, tj=j, s[i][j]='.';
        }
        p[i]=string(m,0);
    }
    queue<ar<int,2>> qu;
    qu.push({si,sj});
    while(!qu.empty()) {
        ar<int,2> u=qu.front();
        qu.pop();
        for(int k=0; k<4; k++) {
            int ni=u[0]+Di[k], nj=u[1]+Dj[k];
            if(e(ni,nj)) {
                s[ni][nj]='#';
                p[ni][nj]=k;
                qu.push({ni,nj});
            }
        }
    }
    if(s[ti][tj]=='.') {
        cout <<"NO\n";
    }
    else {
        cout <<"YES\n";
        string t;
        while(ti^si || tj^sj) {
            int l=p[ti][tj];
            int j=l^2;
            t+= Dc[l];
            ti+=Di[j];
            tj+=Dj[j];
        }
        reverse(t.begin(),t.end());
        cout <<t.size() <<"\n";
        cout <<t;
    }
}
