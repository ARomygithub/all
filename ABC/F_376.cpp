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

const int mxn=3e3;
int n,q;

int sgn(int x) {
    return (x>0) - (x<0);
}
using piii = pair<int,pii>;

void solve() {
    cin >>n >>q;
    map<char,int> mp;
    mp['L'] = 0;
    mp['R'] = 1;
    vi pos = {0,1};
    vi vid(q,-1),vt(q,-1);
    auto slv = [&](vi& ps, vi& psn) -> int {
        if(sgn(ps[0]-ps[1]) == sgn(psn[0]-psn[1])) {
            int x = abs(ps[0]-psn[0]) + abs(ps[1]-psn[1]);
            return min(x,n*2-x);
        } else {
            return n - abs(abs(ps[0]-psn[0]) - abs(ps[1]-psn[1]));
        }
    };
    vector dp(q, vi(n,1e8));
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    rep(i,0,q) {
        char h; int t; cin >>h >>t;
        t--;
        vid[i] = mp[h];
        vt[i] = t;
        if(i==0) {
            rep(j,0,n) {
                if(j==t) continue;
                vi posn(2);
                posn[vid[i]] = t;
                posn[1-vid[i]] = j;
                dp[0][j] = slv(pos,posn);
                pq.push({dp[0][j],{0,j}});
            }
        }
    }    
    while(sz(pq)) {
        auto [d,qiu] = pq.top(); pq.pop();
        auto [qi,u] = qiu;
        if(dp[qi][u]<d) continue;
        if(qi==q-1) continue;
        rep(j,0,n) {
            if(j==vt[qi+1]) continue;
            vi ps(2);
            ps[vid[qi]] = vt[qi];
            ps[1-vid[qi]] = u;
            vi psn(2);
            psn[vid[qi+1]] = vt[qi+1];
            psn[1-vid[qi+1]] = j;
            int nxt = d + slv(ps,psn);
            if(dp[qi+1][j]>nxt) {
                dp[qi+1][j] = nxt;
                pq.push({nxt,{qi+1,j}});
            } 
        }
    }
    int ans = 1e8;
    rep(j,0,n) {
        min_self(ans, dp[q-1][j]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}