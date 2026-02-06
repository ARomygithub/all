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
int n,t;
ll k;

void updAns(int& base, vector<int>& ans, ll& ord) {
    int len = n-base+1;
    int nxt = -1;
    if(len>=62) {
        nxt = base;
        base = nxt+1;
        ans.push_back(nxt);
    } else {
        nxt = base;
        ll s = 0, cur = (len>=2?(1ll<<(len-2)):1);
        while(s + cur <ord) {
            nxt++;
            s += cur;
            cur = max(cur/2,1ll);
        }
        base = nxt+1;
        ans.push_back(nxt);
        ord = ord-s;
    }
}

void solve() {
    cin >>n >>k;
    vector<int> ans;
    int base = 1;
    ll ord = k;
    if(n<=60 && ord > (1ll<<(1ll*(n-1)))) {
        cout <<"-1\n";
        return;
    }
    while(base<=n) {
        updAns(base, ans, ord);
    }
    rep(i,0,sz(ans)) {
        int le = (i>0?ans[i-1]+1:1);
        per(j,ans[i],le-1) {
            cout <<j <<" \n"[i==sz(ans)-1 && j==le];
        }
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