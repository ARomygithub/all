#include <bits/stdc++.h>
using namespace std;

const int N=400005;
struct edge {int to,nxt,id;bool vis;}e[N<<1];
int n,m,ret[N][2],T=0,st[N],top,col,dfn[N],low[N],ans,rt,cnt,head[N];

void addedge(int x,int y,int idx) {e[cnt].to=y;e[cnt].nxt=head[x];e[cnt].id=idx;head[x]=cnt++;}

void dfs(int x) {
    dfn[x]=low[x]=++T;st[++top]=x;
    for (int i=head[x];~i;i=e[i].nxt) {
        int v=e[i].to,idx=e[i].id;
        if(e[i].vis) continue;e[i].vis=e[i^1].vis=1;ret[idx][0]=v;ret[idx][1]=x;
        if(!dfn[v]) dfs(v);
        low[x]=min(low[x],low[v]);
    }
    if(low[x]==dfn[x]) {
        int t=0,cnt=0;
        do {t=st[top--];++cnt;}while(t!=x);
        if(cnt>ans) ans=cnt,rt=x;
    }
}

void scc(int x) {top=T=0;memset(dfn,0,sizeof(dfn));dfs(x);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(head,-1,sizeof(head));
    cin >>n >>m;
    for (int i=1;i<=m;++i) {
        int x,y; cin >>x >>y;
        addedge(x,y,i),addedge(y,x,i);
    }
    scc(1);
    cout <<ans <<"\n";
    for (int i=0;i<cnt;i+=2) e[i].vis=e[i^1].vis=0;
    scc(rt);
    for (int i=1;i<=m;++i) cout <<ret[i][0] <<" " <<ret[i][1] <<"\n";
}