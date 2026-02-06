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
typedef pair<int,pii> pipi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=500;
int n,m;
string s[mxn*2+1];
int ans;
set<pii> st;

vector<vi> treeJump(vi& P){
	int on = 1, d = 1;
	while(on < sz(P)) on *= 2, d++;
	vector<vi> jmp(d, P);
	rep(i,1,d) rep(j,0,sz(P))
		jmp[i][j] = jmp[i-1][jmp[i-1][j]];
	return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
	rep(i,0,sz(tbl))
		if(steps&(1<<i)) nod = tbl[i][nod];
	return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(tbl, a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int i = sz(tbl); i--;) {
		int c = tbl[i][a], d = tbl[i][b];
		if (c != d) a = c, b = d;
	}
	return tbl[0][a];
}

void solve() {
    cin >>n >>m;
    rep(i,0,n*2+1) {
        cin >>s[i];
    }
    vector dp0(n, vector<int>(m, 1e9));
    vector dpn(n, vector<int>(m, 1e9));
    vi par(n*m,0), depth(n*m);
    dp0[0][0] = 0;
    priority_queue<pipi,vector<pipi>,greater<pipi>> pq;
    pq.push({0,{0,0}});
    while(sz(pq)) {
        auto [d, ij] = pq.top(); pq.pop();
        auto [i, j] = ij;
        if(dp0[i][j] <d) continue;
        if(i>0 && s[2*i][2*j+1]=='.') {
            if(dp0[i-1][j] > dp0[i][j]+1) {
                dp0[i-1][j] = dp0[i][j]+1;
                par[(i-1)*m+j] = i*m+j;
                pq.push({dp0[i-1][j],{i-1,j}});
            }
        }
        if(j>0 && s[2*i+1][2*j]=='.') {
            if(dp0[i][j-1] > dp0[i][j]+1) {
                dp0[i][j-1] = dp0[i][j]+1;
                par[i*m+j-1] = i*m+j;
                pq.push({dp0[i][j-1], {i,j-1}});
            }
        }
        if(i+1<n && s[2*(i+1)][2*j+1]=='.') {
            if(dp0[i+1][j] > dp0[i][j]+1) {
                dp0[i+1][j] = dp0[i][j]+1;
                par[(i+1)*m+j] = i*m+j;
                pq.push({dp0[i+1][j], {i+1,j}});
            }
        }
        if(j+1<m && s[2*i+1][2*(j+1)]=='.') {
            if(dp0[i][j+1] > dp0[i][j]+1) {
                dp0[i][j+1] = dp0[i][j]+1;
                par[i*m+j+1] = i*m+j;
                pq.push({dp0[i][j+1],{i,j+1}});
            }
        }
    }
    rep(i,0,n*m) {
        depth[i] = dp0[i/m][i%m];
    }
    dpn[n-1][m-1] = 0;
    // cout <<"TES\n" <<flush;
    priority_queue<pipi,vector<pipi>,greater<pipi>> pq2;
    pq2.push({0,{n-1,m-1}});
    while(sz(pq2)) {
        auto [d, ij] = pq2.top(); pq2.pop();
        auto [i, j] = ij;
        if(dpn[i][j] <d) continue;
        if(i>0 && s[2*i][2*j+1]=='.') {
            if(dpn[i-1][j] > dpn[i][j]+1) {
                dpn[i-1][j] = dpn[i][j]+1;
                pq2.push({dpn[i-1][j],{i-1,j}});
            }
        }
        if(j>0 && s[2*i+1][2*j]=='.') {
            if(dpn[i][j-1] > dpn[i][j]+1) {
                dpn[i][j-1] = dpn[i][j]+1;
                pq2.push({dpn[i][j-1], {i,j-1}});
            }
        }
        if(i+1<n && s[2*(i+1)][2*j+1]=='.') {
            if(dpn[i+1][j] > dpn[i][j]+1) {
                dpn[i+1][j] = dpn[i][j]+1;
                pq2.push({dpn[i+1][j], {i+1,j}});
            }
        }
        if(j+1<m && s[2*i+1][2*(j+1)]=='.') {
            if(dpn[i][j+1] > dpn[i][j]+1) {
                dpn[i][j+1] = dpn[i][j]+1;
                pq2.push({dpn[i][j+1],{i,j+1}});
            }
        }
    }
    ans = dp0[n-1][m-1];
    vector<vi> jmp = treeJump(par);
    function<void(pii,pii)> dfs;
    // cout <<"TES\n" <<flush;
    dfs = [&](pii u, pii p) -> void {
        // cout <<"DFS\n" <<flush;
        st.insert(u);
        int nm = (n-1)*m+m-1;
        vector<pii> vecv;
        if(u.fi>0) {
            pii v = {u.fi-1,u.se};
            if(s[u.fi*2][u.se*2+1]=='.') {
                if(v!=p) dfs({u.fi-1,u.se},u);
            } else {
                vecv.push_back(v);
            }
        }
        if(u.se>0) {
            pii v = {u.fi, u.se-1};
            if(s[u.fi*2+1][u.se*2]=='.') {
                if(v!=p) dfs({u.fi,u.se-1},u);
            } else {
                vecv.push_back(v);
            }
        }
        if(u.fi+1<n) {
            pii v = {u.fi+1,u.se};
            if(s[(u.fi+1)*2][u.se*2+1]=='.') {
                if(v!=p) dfs({u.fi+1,u.se},u);
            } else {
                vecv.push_back(v);
            }
        }
        if(u.se+1<m) {
            pii v = {u.fi,u.se+1};
            if(s[u.fi*2+1][(u.se+1)*2]=='.') {
                if(v!=p) dfs({u.fi,u.se+1},u);
            } else {
                vecv.push_back(v);
            }
        }
        for(auto v : vecv) {
            // cout <<"Vecv\n" <<flush;
            int x = lca(jmp, depth, v.fi*m+v.se, nm);
            // cout <<"af LCA\n" <<flush;
            pii px = {x/m,x%m};
            if(!st.count(px)) {
                max_self(ans, dp0[u.fi][u.se]+dpn[v.fi][v.se]+2);
            }
        }
        st.erase(u);
    };
    dfs({0,0}, {-1,-1});
    cout <<ans <<"\n";
    // rep(i,0,n) {
    //     rep(j,0,m) {
    //         cout <<dp0[i][j] <<" " <<dpn[i][j] <<"\n";
    //     }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}