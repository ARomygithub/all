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
typedef pair<pii,pii> ppii;
typedef pair<int,ppii> ippii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=60;
const int di[4] = {-1,0,1,0}, dj[4] = {0,1,0,-1};
int n;
string s[mxn];
vector dp(mxn, vector(mxn, vector(mxn, vector<int>(mxn, 1e9))));

bool e(pii u) {
    return u.fi>=0&&u.fi<n&&u.se>=0&&u.se<n&&s[u.fi][u.se]!='#';
}

void solve() {
    cin >>n;
    pii s1 = {-1,-1}, s2;
    rep(i,0,n) {
        cin >>s[i];
        rep(j,0,n) {
            if(s[i][j]=='P') {
                if(s1.fi == -1) {
                    s1 = {i,j};
                } else {
                    s2 = {i,j};
                }
            }
        }
    }
    priority_queue<ippii,vector<ippii>,greater<ippii>> pq;
    dp[s1.fi][s1.se][s2.fi][s2.se] = 0;
    pq.push({0,{s1,s2}});
    while(sz(pq)) {
        auto [d, u12] = pq.top(); pq.pop();
        auto [u1, u2] = u12;
        if(dp[u1.fi][u1.se][u2.fi][u2.se]<d) continue;
        rep(k,0,4) {
            pii v1 = {u1.fi+di[k],u1.se+dj[k]};
            pii v2 = {u2.fi+di[k],u2.se+dj[k]};
            if(!e(v1)) {
                v1 = u1;
            }
            if(!e(v2)) {
                v2 = u2;
            }
            if(dp[v1.fi][v1.se][v2.fi][v2.se] > d+1) {
                dp[v1.fi][v1.se][v2.fi][v2.se] = d+1;
                pq.push({d+1,{v1,v2}});
            }
        }
    }
    int ans = 1e9;
    rep(i,0,n) {
        rep(j,0,n) {
            min_self(ans, dp[i][j][i][j]);
        }
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