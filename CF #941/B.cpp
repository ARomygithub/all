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
int n,k,t;

void solve() {
    cin >>n >>k;
    int ai = 1;
    vector<int> ans;
    while(ai*2-1 <k) {
        ans.push_back(ai);
        ai *=2;
    }
    if(k-(ai-1)-1 > 0) {
        ans.push_back(k-(ai-1)-1);
    }
    if(k+1<=n) {
        ai = k+1;
        ans.push_back(ai);
        ai = k*2+1;
        while(ai <= n) {
            ans.push_back(ai);
            ai *=2;
        }
        if(k*3+1 <=n) {
            ans.push_back(k*3+1);
        }
    }
    assert(sz(ans)<=25);
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
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