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
int n,m,t;

void solve() {
    cin >>n >>m;
    int atas = ceil(sqrt(1.0*n+m));
    ll ans = 0;
    rep(p,1,atas) {
        rep(q,1,atas) {
            if(__gcd(p,q)==1) {
                int l1 = (1 + ((p+q)*p-1))/((p+q)*p);
                int l2 = (1 + ((p+q)*q-1))/((p+q)*q);
                max_self(l2, l1);
                int r1 = n/(p*(p+q));
                int r2 = m/(q*(p+q));
                min_self(r2, r1);
                if(r2>=l2) {
                    ans += r2-l2+1;
                }
            }
        }
    }
    cout <<ans <<"\n";
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