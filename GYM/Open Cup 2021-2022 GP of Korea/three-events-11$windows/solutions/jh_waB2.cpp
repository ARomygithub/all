#include <bits/stdc++.h>
#define sz(X) (int)((X).size())
using namespace std;
void OJize(){cin.tie(NULL);ios_base::sync_with_stdio(false);}

// 0-indexed
struct Segtree{
    typedef pair<int,int> T; // b[i], i
    T id = {99999999, 0};
    T combine(T a, T b){
        return min(a, b);
    }

    int n; vector<T> arr;
    Segtree(int sz): n{1}{while(n<sz) n<<=1; arr.resize(n*2, id);}

    void update(int i, T v){
        for(arr[i+=n]=v; i>>=1;)
            arr[i] = combine(arr[i<<1], arr[i<<1|1]);
    }
    T query(int l, int r){
        T resl=id, resr=id;
        for(l+= n, r+= n+1; l < r; l/= 2, r/= 2){
            if(l&1) resl = combine(resl, arr[l++]);
            if(r&1) resr = combine(arr[--r], resr);
        }
        return combine(resl, resr);
    }
};
const pair<int,int> ID = {99999999, 0};

int main(){OJize();
        int n; cin>>n;
    vector<int> A(n), B(n), C(n);
    for(int i=0; i<n; i++) cin>>A[i]>>B[i]>>C[i];

    // kosaraju first half
    Segtree SAB(n+1), SBC(n+1), SCA(n+1);
    vector<bool> vis(n);
    stack<int> S;
    for(int i=0; i<n; i++){
        SAB.update(A[i], {B[i], i});
        SBC.update(B[i], {C[i], i});
        SCA.update(C[i], {A[i], i});
    }
    
    function<void(int)> dfs1;
    dfs1 = [&](int i){
        // mark as visited
        vis[i] = true;
        SAB.update(A[i], ID), SBC.update(B[i], ID), SCA.update(C[i], ID);
        // find adjacent unvisited
        while(1){
            auto pab = SAB.query(0, A[i]);
            if(pab.first < B[i]){dfs1(pab.second); continue;}
            auto pbc = SBC.query(0, B[i]);
            if(pbc.first < C[i]){dfs1(pbc.second); continue;}
            auto pca = SCA.query(0, C[i]);
            if(pca.first < A[i]){dfs1(pca.second); continue;}
            break;
        }
        // done
        S.push(i);
    };
    for(int i=0; i<n; i++) if(!vis[i]) dfs1(i);

    // kosaraju second half
    vector<int> sidx(n, -1);
    for(int i=0; i<n; i++){
        SAB.update(A[i], {-B[i], i});
        SBC.update(B[i], {-C[i], i});
        SCA.update(C[i], {-A[i], i});
    }

    function<void(int, int)> dfs2;
    dfs2 = [&](int i, int num){
        // mark as visited
        sidx[i] = num;
        SAB.update(A[i], ID), SBC.update(B[i], ID), SCA.update(C[i], ID);
        // find adjacent unvisited
        while(1){
            auto pab = SAB.query(A[i], n);
            int rk = -pab.first;
            if(rk > B[i]){dfs2(pab.second, num); continue;}
            auto pbc = SBC.query(B[i], n-1);
            rk = -pbc.first;
            if(rk > C[i]){dfs2(pbc.second, num); continue;}
            auto pca = SCA.query(C[i], n);
            rk = -pca.first;
            if(rk > A[i]){dfs2(pca.second, num); continue;}
            break;
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
        if(sidx[a-1] >= sidx[b-1]) cout << "YES\n";
        else cout << "NO\n";
    }
}