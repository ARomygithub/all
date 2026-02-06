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

const int mxn=2e5;
int n;
int a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n-1) {
        cin >>b[i];
    }
    sort(a,a+n);
    sort(b,b+n-1);
    per(i,n-2,-1) {
        if(b[i]<a[i+1]) {
            int ans = a[i+1];
            bool ok = 1;
            per(j,i,-1) {
                ok = ok && (b[j]>=a[j]);
                if(!ok) break;
            }
            if(ok) {
                cout <<ans <<"\n";
            } else {
                cout <<"-1\n";
            }
            return;
        }
    }
    cout <<a[0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}