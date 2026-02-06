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

const int mxn=1e5;
int n,k,t;

void solve() {
    cin >>n >>k;
    vector<int> ans;
    ans.push_back(1<<(k-1));
    priority_queue<int,vector<int>,greater<int>> pq;
    // map<int,bool> mp;
    rep(i,0,k) {
        // mp[1<<i] = 1;
        pq.push(1<<i);
    }
    rep(i,1,n) {
        if(i>=(1<<(k-1))) {
            ans.push_back(1);
            continue;
        }
        auto u = pq.top(); pq.pop();
        u = u*2+1;
        pq.push(u);
        while((u) < (1<<(k-1))) {
            u *=2;
            pq.push(u);
        }
        ans.push_back(u);
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
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