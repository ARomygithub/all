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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n;
vector<int> adj[17];
vector<vector<ll>> dp(1<<16, vector<ll>(17,-1));
ll ans=0;
vector<int> vans = {1};

void dfs(int state, int last, int u) {
    int state_new = state | (1<<(u-1));
    ll temp = 
    max_self(dp[state_new][u], dp[state][last]+)
}

void solve() {
    cin >>n;
    adj[1] = {7, 10};
    adj[2] = {9, 11, 8};
    adj[3] = {5, 10, 12};
    adj[4] = {6, 11};
    adj[5] = {3, 11, 14};
    adj[6] = {4, 12, 15, 13};
    adj[7] = {1, 9, 14, 16};
    adj[8] = {10, 15, 2};
    adj[9] = {15, 7, 2};
    adj[10] = {1, 3, 8, 16};
    adj[11] = {2, 5, 4, 13};
    adj[12] = {3, 6, 14};
    adj[13] = {6, 11};
    adj[14] = {5, 7, 12};
    adj[15] = {9, 6, 8};
    adj[16] = {7, 10};
    for(int awal=0;awal<16;awal++) {
        dp[(1<<awal)][awal+1] = 0; 
        for(int u=1;u<=16;u++) {
            if(u!=awal+1) {
                dfs((1<<awal),awal+1,u);
            }
        }
    }
    cout <<ans <<"\n";
    for(int i=0;i<sz(vans);i++) {
        cout <<vans[i] <<" \n"[i==sz(vans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}