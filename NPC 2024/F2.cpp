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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3, inf=1e9;
const pii d[4] = {{0,0},{0,-1},{-1,-1},{-1,0}};
int n,m;
int p[mxn][mxn];
// using piii = pair<pii,int>;
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>m;
    vector h(n+2, vector(m+2, vector<bool>(4,0)));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>p[i][j];
            if(p[i][j]>0) {
                int x = i - d[p[i][j]-1].fi;
                int y = j - d[p[i][j]-1].se;
                h[x+1][y+1][p[i][j]-1] = 1;
            }
        }
    }
    vector dp(n, vector(m, vi(4,1e9)));
    dp[0][0][0] = 0;
    priority_queue<ipii, vector<ipii>, greater<ipii>> pq;
    pq.push({0, {0,0}});
    while(sz(pq)) {
        auto [dd, ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        assert(dd<inf);
        if(dp[i][j][dd%4] < dd) continue;
        int ddn = dd+1;
        int rn = ddn%4;
        // diam
        {
            if(dp[i][j][rn] > ddn) {
                bool ok = 1;
                for(int ih=i;ih<=i+1;ih++) {
                    for(int jh=j;jh<=j+1;jh++) {
                        rep(off,0,4) {
                            if(h[ih+1][jh+1][off]) {
                                pii nxt = {ih+d[(off+rn)%4].fi, jh+d[(off+rn)%4].se};
                                if(nxt.fi == i && nxt.se ==j) {
                                    ok = 0;
                                    break;
                                }
                            }
                        }
                        if(!ok) break;
                    }
                    if(!ok) break;
                }
                if(ok) {
                    dp[i][j][rn] = ddn;
                    pq.push({ddn, {i,j}});
                }
            }
        }
        if(i+1<n) {
            int in = i+1;
            int jn = j;
            if(dp[in][jn][rn] > ddn) {
                if(in==n-1 && jn==m-1) {
                    dp[in][jn][rn] = ddn;
                }
                bool ok = 1;
                for(int ih=in;ih<=in+1;ih++) {
                    for(int jh=jn;jh<=jn+1;jh++) {
                        rep(off,0,4) {
                            if(h[ih+1][jh+1][off]) {
                                pii nxt = {ih+d[(off+rn)%4].fi, jh+d[(off+rn)%4].se};
                                if(nxt.fi == in && nxt.se ==jn) {
                                    ok = 0;
                                    break;
                                }
                                pii cur = {ih+d[(off+rn+3)%4].fi,jh+d[(off+rn+3)%4].se};
                                if(nxt.fi==i && nxt.se==j && cur.fi==in && cur.se==jn) {
                                    ok = 0;
                                    break;
                                }
                            }
                        }
                        if(!ok) break;
                    }
                    if(!ok) break;
                }                
                if(ok) {
                    dp[in][jn][rn] = ddn;
                    pq.push({ddn, {in,jn}});
                }
            }
        }
        if(j+1<m) {
            int in = i, jn = j+1;
            if(dp[in][jn][rn] > ddn) {
                if(in==n-1 && jn==m-1) {
                    dp[in][jn][rn] = ddn;
                }            
                bool ok = 1;
                for(int ih=in;ih<=in+1;ih++) {
                    for(int jh=jn;jh<=jn+1;jh++) {
                        rep(off,0,4) {
                            if(h[ih+1][jh+1][off]) {
                                pii nxt = {ih+d[(off+rn)%4].fi, jh+d[(off+rn)%4].se};
                                if(nxt.fi == in && nxt.se ==jn) {
                                    ok = 0;
                                    break;
                                }
                                pii cur = {ih+d[(off+rn+3)%4].fi,jh+d[(off+rn+3)%4].se};
                                if(nxt.fi==i && nxt.se==j && cur.fi==in && cur.se==jn) {
                                    ok = 0;
                                    break;
                                }
                            }
                        }
                        if(!ok) break;
                    }
                    if(!ok) break;
                }                
                if(ok) {
                    dp[in][jn][rn] = ddn;
                    pq.push({ddn, {in,jn}});
                }
            }
        }
    }
    int ans = 1e9;
    rep(i,0,4) {
        min_self(ans, dp[n-1][m-1][i]);
    }
    if(ans==1e9) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}