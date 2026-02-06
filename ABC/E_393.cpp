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

const int mxn=12e5,mxa=1e6;
int n,k;
int ct[mxa+1];

void solve() {
    cin >>n >>k;
    vi a(n);
    rep(i,0,n) {
        cin >>a[i];
        ct[a[i]]++;
    }
    vector<bool> ok(mxa+1,0);
    rep(i,1,mxa+1) {
        int cur = 0;
        for(int j=i;j<=mxa;j+=i) {
            cur += ct[j];
            if(cur>=k) break;
        }
        ok[i] = (cur>=k);
    }
    vi ans(mxa+1,1);
    rep(i,2,mxa+1) {
        if(ok[i]) {
            for(int j=i;j<=mxa;j+=i) {
                ans[j] = i;
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[a[i]] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}