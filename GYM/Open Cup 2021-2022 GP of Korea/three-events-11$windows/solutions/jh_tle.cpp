#include <bits/stdc++.h>
#define sz(X) (int)((X).size())
#define entire(X) X.begin(),X.end()
using namespace std; typedef long long ll;
void OJize(){cin.tie(NULL);ios_base::sync_with_stdio(false);}
template <class T1, class T2>ostream&operator<<(ostream &os,pair<T1,T2>const&x){os<<'('<<x.first<<", "<<x.second<<')';return os;}
template <class Ch, class Tr, class Container>basic_ostream<Ch,Tr>&operator<<(basic_ostream<Ch,Tr>&os,Container const&x){for(auto&y:x)os<<y<<" ";return os;}

struct DisjointSet{
    vector<int> par;
    DisjointSet(int n): par(n) {iota(entire(par), 0);}
    void un(int x, int y){par[fd(x)] = fd(y);} // yr becomes parent
    int fd(int x){return par[x]!=x? (par[x]=fd(par[x])):x;}
};

int main(){OJize();
    int n; cin>>n;
    vector<int> A(n), B(n), C(n);
    for(int i=0; i<n; i++) cin>>A[i]>>B[i]>>C[i];

    // kosaraju first half
    vector<bool> vis(n);
    stack<int> S;
    
    function<void(int)> dfs1;
    DisjointSet SKIP(n+1);
    vector<int> ptr(n);
    dfs1 = [&](int i){
        // mark as visited
        vis[i] = true;
        SKIP.un(i, i+1);
        // find adjacent unvisited
        ptr[i] = SKIP.fd(0);
        while(ptr[i] < n){
            int j = ptr[i];
            int won = (A[i] < A[j]) + (B[i] < B[j]) + (C[i] < C[j]);
            if(won >= 2) dfs1(j);
            ptr[i] = SKIP.fd(j+1);
        }
        // done
        S.push(i);
    };
    for(int i=0; i<n; i++) if(!vis[i]) dfs1(i);

    // kosaraju second half
    vector<int> sidx(n, -1);

    function<void(int, int)> dfs2;
    iota(entire(SKIP.par), 0);
    fill(entire(ptr), 0);
    dfs2 = [&](int i, int num){
        // mark as visited
        sidx[i] = num;
        SKIP.un(i, i+1);
        // find adjacent unvisited
        ptr[i] = SKIP.fd(0);
        while(ptr[i] < n){
            int j = ptr[i];
            int won = (A[j] < A[i]) + (B[j] < B[i]) + (C[j] < C[i]);
            if(won >= 2) dfs2(j, num);
            ptr[i] = SKIP.fd(j+1);
        }
    };
    int num = 0;
    while(!S.empty()){
        int v = S.top(); S.pop();
        if(sidx[v] == -1) dfs2(v, num++);
    }
    
    int Q; cin>>Q;
    while(Q--){
        int a, b; cin>>a>>b;
        if(sidx[a-1] <= sidx[b-1]) cout << "YES\n";
        else cout << "NO\n";
    }
}