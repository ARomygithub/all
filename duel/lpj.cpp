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
int n;
int a[] = {880000, 230000, 800000, 3505209, 994800, 84000, 36000, 84000, 173000, 650000, 2251067, 6202025};

void solve() {
    n = 12;
    vi ans;
    int tot = 8000000, mn = tot;
    rep(bit,0,(1<<n)) {
        vi cur;
        int sm = 0;
        rep(i,0,n) {
            if((bit>>i)&1) {
                cur.push_back(i);
                sm += a[i];
            }
        }
        if(abs(tot-sm)<mn) {
            mn = abs(tot-sm);
            ans.swap(cur);
        }
    }
    cout <<mn <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
    rep(i,0,sz(ans)) {
        cout <<a[ans[i]] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}