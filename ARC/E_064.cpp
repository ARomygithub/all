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
int n;
pii s,t, c[mxn];
int r[mxn];

void solve() {
    cin >>s.fi >>s.se >>t.fi >>t.se;
    cin >>n;
    rep(i,0,n) {
        cin >>c[i].fi >>c[i].se >>r[i];
    }
    vector<double> dp(n);
    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
    rep(i,0,n) {
        dp[i] = max(0.0, hypot(1.0*abs(c[i].fi-t.fi),1.0*abs(c[i].se-t.se))-r[i]);
        pq.push({dp[i],i});
    }
    while(sz(pq)) {
        auto [di, i] = pq.top(); pq.pop();
        if(di>dp[i]) continue;
        rep(j,0,n) {
            if(j==i) continue;
            double temp = max(0.0, hypot(1.0*abs(c[i].fi-c[j].fi),1.0*abs(c[i].se-c[j].se))-r[i]-r[j]);
            if(temp+dp[i]<dp[j]) {
                dp[j] = temp+dp[i];
                pq.push({dp[j],j});
            }
        }
    }
    double ans = hypot(1.0*abs(t.fi-s.fi),1.0*abs(t.se-s.se));
    rep(i,0,n) {
        double temp = dp[i] + max(0.0, hypot(1.0*abs(c[i].fi-s.fi),1.0*abs(c[i].se-s.se)) - r[i]);
        min_self(ans, temp);
    }
    cout <<fixed <<setprecision(10) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}