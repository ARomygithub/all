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
double y[mxn];
int x[mxn];
const double eps = 1e-9;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>x[i] >>y[i];
    }
    double ans = -1;
    {
        double cek0 = 1;
        ll ls = -1e15;
        ll bls = 1;
        rep(i,0,n) {
            // double cur = atan2(y[i]-mid,x[i])*1e5;
            ll cur = (y[i]);
            // cout <<fixed <<setprecision(12) <<cur <<" ";        
            if(cur*bls<=ls*x[i]) {
                cek0 = 0;
                break;
            }
            ls = cur;
            bls = x[i];
        }
        // cout <<endl;
        if(!cek0) {
            ans = 0;
        }
    }

    double l = 0, r = 1e9;
    // cout <<fixed <<setprecision(12) <<eps <<endl;            
    while(l+eps<=r) {
        double mid = (l+r)/2;
        // cout <<fixed <<setprecision(12) <<mid <<endl;        
        bool ok = 1;
        double ls = -1e15;
        int bls = 1;
        rep(i,0,n) {
            // double cur = atan2(y[i]-mid,x[i])*1e5;
            double cur = (y[i]-mid);
            // cout <<fixed <<setprecision(12) <<cur <<" ";        
            if(cur*bls<=ls*x[i]) {
                ok = 0;
                break;
            }
            ls = cur;
            bls = x[i];
        }
        // cout <<endl;
        if(!ok) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    if(ans<0) {
        cout <<"-1\n";
    } else {
        cout <<fixed <<setprecision(12) <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}