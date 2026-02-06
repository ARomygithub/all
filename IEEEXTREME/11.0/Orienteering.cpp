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
typedef pair<double,pii> pdpi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=6e2;
const int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int n,m,p;
double r[mxn][mxn], h[mxn][mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m;
}

void solve() {
    cin >>n >>m;
    cin >>p;
    vector<pii> v(p+1);
    for(int i=0;i<=p;i++) {
        cin >>v[i].fi >>v[i].se;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>r[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>h[i][j];
        }
    }
    double ans=0;
    for(int i0=0;i0<p;i0++) {
        vector<vector<double>> dp(n,vector<double>(m,4e18));
        priority_queue<pdpi,vector<pdpi>,greater<pdpi>> pq;
        dp[v[i0].fi][v[i0].se] = 0;
        pq.push({0.0,v[i0]});
        while(sz(pq)) {
            auto [d,ij] = pq.top(); pq.pop();
            auto [i,j] = ij;
            if(dp[i][j]<d) continue;
            if(ij==v[i0+1]) {
                ans +=dp[i][j];
                // cout <<dp[i][j] <<"\n";
                break;
            }
            for(int k=0;k<4;k++) {
                int ii=i+di[k],jj=j+dj[k];
                if(e(ii,jj)) {
                    double leni = (r[i][j]+r[ii][jj])/2*exp(3.5*abs(((h[ii][jj]-h[i][j])/10) + 0.05));
                    if(dp[ii][jj]>leni+d) {
                        dp[ii][jj] = leni+d;
                        pq.push({dp[ii][jj],{ii,jj}});
                    }
                }
            }
        }
    }
    cout <<ceil(ans) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}