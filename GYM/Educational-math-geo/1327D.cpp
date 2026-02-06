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
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
int p[mxn],c[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>p[i];
        p[i]--;
    }
    rep(i,0,n) {
        cin >>c[i];
    }
    int ans = n;
    vector<bool> vis(n, 0);
    vector<int> v;
    rep(i,0,n) {
        if(!vis[i]) {
            v.clear();
            int u = i;
            vis[u] = 1;
            v.push_back(u);
            u = p[u];
            while(u!=i) {
                v.push_back(u);
                vis[u] = 1;
                u = p[u];
            }
            rep(j,1,sz(v)+1) {
                if(j>=ans) break;
                if((sz(v)%j)==0) {
                    rep(k,0,j) {
                        set<int> s;
                        for(int id = k; id<sz(v);id += j) {
                            s.insert(c[v[id]]);
                            if(sz(s)>1) {
                                break;
                            }
                        }
                        if(sz(s)==1) {
                            min_self(ans, j);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout <<ans <<"\n";
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