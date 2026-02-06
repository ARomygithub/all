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

const int mxn=3;
int n;
ll a[mxn][mxn];
vector<pii> mv;
int vis[mxn][mxn];
ll sum =0;

bool end(int who) {
    int cl = who+1;
    rep(i,0,n) {
        set<int> s;
        rep(j,0,n) {
            s.insert(vis[i][j]);
        }
        if(sz(s)==1 && (*s.begin())==cl) {
            return 1;
        }
    }
    rep(j,0,n) {
        set<int> s;
        rep(i,0,n) {
            s.insert(vis[i][j]);
        }
        if(sz(s)==1 && (*s.begin()==cl)) {
            return 1;
        }
    }
    {
        set<int> s;
        rep(i,0,n) {
            s.insert(vis[i][i]);
        }
        if(sz(s)==1 && (*s.begin())==cl) {
            return 1;
        }
    }
    {
        set<int> s;
        rep(i,0,n) {
            s.insert(vis[i][2-i]);
        }
        if(sz(s)==1 && (*s.begin())==cl) {
            return 1;
        }
    }
    return 0;
}

bool move(int pos) {
    bool iWin = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            if(!vis[i][j]) {
                vis[i][j] = 1 + (pos%2);
                if(end(pos%2)) {
                    iWin = 1;
                    vis[i][j] = 0;
                    break;
                }
                mv.push_back({i,j});
                if(sz(mv)==9) {
                    ll si = 0;
                    for(int ii=0;ii<9;ii+=2) {
                        si += a[mv[ii].fi][mv[ii].se];
                    }
                    if(si*2>sum) {
                        iWin = 1;
                    }
                } else {
                    bool opWin = move(pos+1);
                    if(!opWin) {
                        iWin = 1;
                    }
                }
                mv.pop_back();
                vis[i][j] = 0;
                if(iWin) break;
            }
        }
        if(iWin) break;
    }
    return iWin;
}

void solve() {
    n = 3;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>a[i][j];
            sum += a[i][j];
        }
    }
    bool w = move(0);
    if(w) {
        cout <<"Takahashi\n";
    } else {
        cout <<"Aoki\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}