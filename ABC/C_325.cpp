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
const int di[8]={-1,-1,0,1,1,1,0,-1}, dj[8]={0,1,1,1,0,-1,-1,-1};
int h,w;
string s[mxn];
int ct=0;

bool e(int i, int j) {
    return i>=0&&i<h&&j>=0&&j<w&&s[i][j]=='#';
}

void dfs(int i, int j) {
    s[i][j] = '.';
    for(int k=0;k<8;k++) {
        int ii=i+di[k],jj=j+dj[k];
        if(e(ii,jj)) {
            dfs(ii,jj);
        }
    }
}

void solve() {
    cin >>h >>w;
    for(int i=0;i<h;i++) {
        cin >>s[i];
    }
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(s[i][j]=='#') {
                ct++;
                dfs(i,j);
            }
        }
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}