int s[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    for(int b : adj[a]) {
        dfs(b,a);
        s[a] +=s[b];
    }
}
-------------------------------------------------------------------
int dp0[mxn], dp1[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        dp1[a] = max(dp1[a]+max(dp0[b],dp1[b]), dp0[a]+dp0[b]+1);
        dp0[a] += max(dp0[b],dp1[b]);
    }
}
-------------------------------------------------------------------
int d[mxn], ans;
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        ans = max(ans, d[a]+d[b]+1);
        d[a] = max(d[a],d[b]+1);
    }
}
-------------------------------------------------------------------
int ml1[mxn][2], ml2[mxn][2];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        if(ml1[a][0]<=ml1[b][0]+1) {
            ml2[a][0] = ml1[a][0]; ml2[a][1] = ml1[a][1];
            ml1[a][0]=ml1[b][0]+1; ml1[a][1] =b;
        } else if(ml2[a][0]<=ml1[b][0]+1) {
            ml2[a][0] = ml1[b][0]+1; ml2[a][1]=b;
        }
    }
}

void dfs2(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        if(ml1[a][1]!=b) {
            if(ml1[a][0]+1>=ml1[b][0]) {
                ml2[b][0]=ml1[b][0]; ml2[b][1]=ml1[b][1];
                ml1[b][0]=ml1[a][0]+1; ml1[b][1]=a;
            } else if(ml1[a][0]+1>=ml2[b][0]){
                ml2[b][0]=ml1[a][0]+1; ml2[b][1]=a;
            }
        } else {
            if(ml2[a][0]+1>=ml1[b][0]) {
                ml2[b][0]=ml1[b][0]; ml2[b][1]=ml1[b][1];
                ml1[b][0]=ml2[a][0]+1; ml1[b][1]=a;
            } else if(ml2[a][0]+1>=ml2[b][0]){
                ml2[b][0]=ml2[a][0]; ml2[b][1]=a;
            }
        }
        dfs2(b,a);
    }
}
-------------------------------------------------------------------
int ml1[mxn], ans[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs(b,a);
        ml1[a]=max(ml1[a],ml1[b]+1);
    }
}

void dfs2(int a=0, int p=-1, int pd=0) {
    ans[a] =max(ml1[a],pd);
    vector<ar<int,2>> w {{pd,-1}};
    for(int b : adj[a]) {
        if(b==p) continue;
        w.push_back({ml1[b]+1,b});
    }
    w.push_back({0,-1});
    sort(w.begin(),w.end(),greater<ar<int,2>>());
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs2(b,a,w[0][1]==b?w[1][0]+1:w[0][0]+1);
    }
}
-------------------------------------------------------------------
int d[mxn];
ll ans[mxn], s[mxn];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
        s[a] +=s[b];
    }
}

void dfs2(int a=0, ll pd=0, int p=-1) {
    ans[a] =pd;
    for(int b : adj[a]) {
        if(b==p) continue;
        dfs2(b,pd-s[b]+(n-s[b]),a);
    }
}
-------------------------------------------------------------------
int d[mxn], anc[mxn][18];
vector<int> adj[mxn];
 
void dfs(int a=0, int p=-1) {
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
    }
}
-------------------------------------------------------------------
int d[mxn], anc[mxn][18];
vector<int> adj[mxn];

void dfs(int a=0, int p=-1) {
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
    }
}

int lca(int x, int k) {
    if(d[x]<d[k]) swap(x,k);
    for(int i=17;~i;i--) {
        if(d[x]-(1<<i)>=d[k]) x =anc[x][i];
    }
    if(x==k) return x;
    for(int i=17;~i;i--) {
        if(anc[x][i]^anc[k][i]) {
            x = anc[x][i]; k=anc[k][i];
        }
    }
    return anc[x][0];
}
-------------------------------------------------------------------
while(q--) {
    int x,k; cin >>x >>k; x--, k--;
    cout <<d[x]+d[k]-2*d[lca(x,k)] <<"\n";
}
-------------------------------------------------------------------
int d[mxn], s[mxn];
vector<int> adj[mxn], v[mxn];

void dfs(int a=0, int p=-1) {
    s[a]=1;
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
        s[a] +=s[b];
        v[a].push_back(s[b]);
    }
    v[a].push_back(n-s[a]);
}
-------------------------------------------------------------------
void dfs2(int a=0, int p=-1) {
    for(int b : adj[a]) {
        if(b^p) {
            dfs2(b,a);
            c[a] +=c[b];
        }
    }
    ans[a]=c[a];
}
    for(int i=0;i<m;i++) {
        int a,b; cin >>a >>b; a--, b--;
        ++c[a], ++c[b];
        int d= lca(a,b);
        -- c[d];
        if(d) --c[anc[d][0]];
    }
-------------------------------------------------------------------
int ds[mxn], de[mxn], dt;

void dfs(int a=0, int p=-1) {
    s[a]=1;
    anc[a][0]=p;
    for(int i=1;i<18;i++) {
        anc[a][i]= ~anc[a][i-1]?anc[anc[a][i-1]][i-1]:-1;
    }
    ds[a] =dt++;
    for(int b : adj[a]) {
        if(b==p) continue;
        d[b]=d[a]+1;
        dfs(b,a);
        s[a] +=s[b];
    }
    de[a]=dt;
}


