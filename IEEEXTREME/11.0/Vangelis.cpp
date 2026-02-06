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
int n,m,t;
int p[mxn],cs[mxn];

int find(int x) {
    return x==p[x]?x:(p[x]=find(p[x]));
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return false;
    }
    if(cs[x]>cs[y]) swap(x,y);
    cs[y] +=cs[x];
    p[x] = y;
    return true;
}

void solve() {
    cin >>n >>m;
    bool loop=false;
    iota(p,p+n,0);
    fill(cs,cs+n,1);
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v;
        if(u==v) {
            loop = 1;
            continue;
        }
        if(!join(u,v)) {
            loop = 1;
        }
    }
    cout <<loop <<"\n";
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