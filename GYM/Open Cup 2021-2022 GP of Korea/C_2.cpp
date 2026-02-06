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

const int mxn=1e5;
int n;
int ct[10];
int cur = 0;

void dfs(int now, int sisa, int big) {
    if(sisa==0) {
        now++, sisa = 10, big=9;
    }
    max_self(cur,now);
    if(sisa<=big && ct[sisa]>0) {
        ct[sisa]--;
        dfs(now,0,big);
        ct[sisa]++;
        return;
    }
    per(i,min(sisa,big),0) {
        if(ct[i]) {
            ct[i]--;
            dfs(now,sisa-i,i);
            ct[i]++;
        }
    }
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        int ai; cin >>ai;
        ct[ai]++;
    }
    int ans = 0;
    ans += ct[5]/2;
    ct[5] %=2;
    rep(i,1,5) {
        int temp = min(ct[i],ct[10-i]);
        ans += temp;
        ct[i] -=temp;
        ct[10-i] -= temp;
    }
    dfs(0,10,9);
    cout <<ans + cur <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}