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

const int mxn=1e3;
const int di[4] = {-1,0,1,0}, dj[4] = {0,1,0,-1};
int n,m;
string s[mxn];
bool vis[mxn][mxn], one[mxn][mxn];
int cur = 0;
set<pii> sone;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]!='#';
}

void dfs(int i, int j) {
    vis[i][j] = 1;
    cur++;
    rep(k,0,4) {
        int ii=i+di[k], jj=j+dj[k];
        if(e(ii,jj)) {
            if(one[ii][jj]) {
                sone.insert({ii,jj});
            } else if(!vis[ii][jj]) {
                dfs(ii,jj);
            }
        }
    }
}

void dfs_clear(int i, int j) {
    vis[i][j] = 0;
    rep(k,0,4) {
        int ii=i+di[k], jj=j+dj[k];
        if(e(ii,jj)) {
            if(one[ii][jj]) {
                // sone.insert({ii,jj});
            } else if(vis[ii][jj]) {
                dfs(ii,jj);
            }
        }
    }
}

void solve() {
    cin >>n >>m;
    // n = rng()%10;
    // m = rng()%10;
    int ans = 0;
    rep(i,0,n) {
        cin >>s[i];
        // int ct = rng()%m;
        // s[i] = "";
        // rep(j,0,m) {
        //     s[i] += '.';
        // }
        // rep(j,0,ct) {
        //     s[i][j] = '#';
        // }
        // shuffle(s[i].begin(), s[i].end(), rng);
    }
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='#') {
                vis[i][j] = 1;
                rep(k,0,4) {
                    int ii = i+di[k], jj=j+dj[k];
                    if(e(ii,jj)) {
                        one[ii][jj] = 1;
                        s[ii][jj] = '1';
                        ans = 1;
                    }
                }
            }
        }
    }
    int ans2 = ans;
    rep(i,0,n) {
        rep(j,0,m) {
            if((!vis[i][j]) && (!one[i][j])) {
                cur = 0;
                sone.clear();
                dfs(i,j);
                if(cur + sz(sone) == 19) {
                    cout <<i <<" " <<j <<endl;
                }
                max_self(ans, cur + sz(sone));
            }
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            if(vis[i][j] && s[i][j]!='#') {
                vis[i][j] = 0;
            }
        }
    }
    rep(i,0,n) {
        rep(j,0,m) {
            if((!vis[i][j]) && (!one[i][j])) {
                cur = 0;
                sone.clear();
                dfs(i,j);
                max_self(ans2, cur + sz(sone));
                dfs_clear(i,j);
            }
        }
    }
    if(ans !=ans2) {
        cout <<n <<" " <<m <<endl;
        rep(i,0,n) {
            cout <<s[i] <<endl;
        }
        cout <<ans <<endl;
        cout <<ans2 <<endl;
    }
    assert(ans==ans2);
    // rep(i,0,n) {
    //     rep(j,0,m) {
    //         assert(vis[i][j] || one[i][j]);
    //     }
    // }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}