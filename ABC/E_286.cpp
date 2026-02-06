#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
#define pil pair<int,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=300;
int n;
pil dist[mxn][mxn];
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            char c; cin >>c;
            if(i==j) {
                dist[i][j] = {0,a[i]};
            } else {
                if(c=='Y') {
                    dist[i][j] = {1,1ll*a[i]+a[j]};
                } else {
                    dist[i][j] = {1e9,0};
                }
            }
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ll temp2 = dist[i][k].se+dist[k][j].se-a[k];
                int temp = dist[i][k].fi+dist[k][j].fi;
                if(dist[i][j].fi>temp || (dist[i][j].fi==temp && dist[i][j].se<temp2)) {
                    dist[i][j] = {temp,temp2};
                }
            }
        }
    }
    int q; cin >>q;
    while(q--) {
        int u,v; cin >>u >>v; u--,v--;
        if(dist[u][v].fi==1e9) {
            cout <<"Impossible\n";
        } else {
            cout <<dist[u][v].fi <<" " <<dist[u][v].se <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}