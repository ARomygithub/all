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

const int mxn=1e5;
int a[3][3];
bool vis[3][3];
int ct=0;

void dfs(int i, int j, int order) {
    vis[i][j] = 1;
    bool falseHope = false;
    vector<int> rowi;
    for(int jj=0;jj<3;jj++) {
        if(jj!=j && vis[i][jj]) {
            rowi.push_back(a[i][jj]);
        }
    }
    falseHope |= (sz(rowi)==2) && (rowi[0]==rowi[1]);
    vector<int> coli;
    for(int ii=0;ii<3;ii++) {
        if(ii!=i && vis[ii][j]) {
            coli.push_back(a[ii][j]);
        }
    }
    falseHope |= (sz(coli)==2) && (coli[0]==coli[1]);
    if(i==j) {
        vector<int> diag1;
        for(int ii=0;ii<3;ii++) {
            if(ii!=i && vis[ii][ii]) {
                diag1.push_back(a[ii][ii]);
            }
        }
        falseHope |= (sz(diag1)==2) && (diag1[0]==diag1[1]);
    }
    if(i+j==2) {
        vector<int> diag2;
        for(int ii=0;ii<3;ii++) {
            if(ii!=i && vis[ii][2-ii]) {
                diag2.push_back(a[ii][2-ii]);
            }
        }
        falseHope |= (sz(diag2)==2) && (diag2[0]==diag2[1]);
    }
    if(falseHope) {
        vis[i][j]=0;
        return;
    }
    if(order==9) {
        ct++;
    }
    for(int ii=0;ii<3;ii++) {
        for(int jj=0;jj<3;jj++) {
            if(!vis[ii][jj]) {
                dfs(ii,jj,order+1);
            }
        }
    }
    vis[i][j] = 0;
}

void solve() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >>a[i][j];
        }
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            dfs(i,j,1);
        }
    }
    int fact = 1;
    for(int i=1;i<=9;i++) {
        fact *=i;
    }
    double ans = 1.0*ct/fact;
    cout <<fixed <<setprecision(10) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}