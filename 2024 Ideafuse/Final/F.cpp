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
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    int r= 0;
    int ct = 0;
    int ans = 0;
    rep(l,0,n) {
        while(r!=l+n) {
            if(a[r%n]==1) {
                r++;
            } else if(ct<k) {
                ct++;
                r++;
            } else {
                break;
            }
        }
        max_self(ans, r-l);
        if(r==l) {
            r++;
        } else {
            ct -= (a[l%n]==0);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    rep(i,1,t+1) {
        cout <<"CASE #" <<i <<": ";
        solve();
    }
}