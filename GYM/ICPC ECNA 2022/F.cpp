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
ll r,s,h;
#define _USE_MATH_DEFINES
const long double pi = 3.14159265358979323846;

void solve() {
    cin >>r >>s >>h;
    long double alpha = pi*2*r/(s*h);
    alpha = min(ceill(alpha)-alpha, alpha-floorl(alpha));
    int n1=-1,n2=-1,n3=-1;
    long double mn = 1e9;
    rep(i,2,251) {
        rep(j,2,251) {
            if(i*j*2>1000) break;
            rep(k,2,251) {
                if(i*j*k>1000) break;
                long double tmp = abs(1.0L*(j*k-k+1)/(i*j*k) - alpha);
                if(tmp<mn) {
                    mn = tmp;
                    n1 = i;
                    n2 = i*j;
                    n3 = i*j*k;
                }
            }
        }
    }
    cout <<n1 <<" " <<n2 <<" " <<n3 <<"\n";
    // cout <<fixed <<setprecision(5) << <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}