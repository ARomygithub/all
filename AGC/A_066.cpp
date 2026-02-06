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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=500;
const int di[4] = {-1,0,1,0}, dj[4]= {0,1,0,-1};
int n,d;
int a[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<n;
}

void solve() {
    cin >>n >>d;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>a[i][j];
        }
    }
    vector<ipii> v;
    rep(i,0,n) {
        rep(j,0,n) {
            v.push_back({a[i][j],{i,j}});
        }
    }
    sort(v.begin(),v.end());
    int cost = 0;
    vector ans(n, vector<int>(n, -1e9));
    for(auto [val, ij]: v) {
        auto [i,j] = ij;
        int mx = -1e9;
        rep(k,0,4) {
            int ii = i+di[k], jj = j+dj[k];
            if(e(ii,jj)) {
                max_self(mx, ans[ii][jj]);
            }
        }
        int r = ((val%d)+d)%d;
        int rmx = ((mx%d)+d)%d;
        if(rmx) {
            mx += d-rmx;
        }
        int ansi= max(val-r, mx+d);
        // if()
        ans[i][j] = ansi;
    }
    vector<int> diff;
    rep(i,0,n) {
        rep(j,0,n) {
            diff.push_back(ans[i][j]-a[i][j]);
        }
    }
    sort(diff.begin(),diff.end());
    int mid = diff[(n*n+2)/2 -1];
    rep(i,0,n) {
        rep(j,0,n) {
            ans[i][j] -= mid;
            cost += abs(ans[i][j]-a[i][j]);
        }
    }
    // assert(cost <= (d*n*n)/2);
    rep(i,0,n) {
        rep(j,0,n) {
            cout <<ans[i][j] <<" \n"[j==n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}