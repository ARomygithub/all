#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m, p[mxn];
vector<int> cs(mxn,1);

int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return 0;
    }
    if (cs[x]>cs[y]) swap(x,y);
    cs[y]=cs[x]+cs[y];
    p[x]=y;
    return 1;
    //update cs juga
}

void solve() {
    cin >>n >>m;
    iota(p,p+n,0);
    int ans=0;
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        if(!join(u,v)) {
            ans++;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}