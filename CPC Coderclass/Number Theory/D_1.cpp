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
int n,m;

double fastexpo(double a, int b) {
    double ret = 1.0;
    while(b) {
        if(b&1) {
            ret = ret*a;
        }
        a = a*a;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>m >>n;
    vector<double> p(m);
    rep(i,0,m) {
        double cur = 1.0*(i+1)/m;
        p[i] = fastexpo(cur, n);
    }
    double ans = 0;
    rep(i,0,m) {
        double cur = p[i];
        if(i>0) {
            cur -= p[i-1];
        }
        ans += cur*(i+1);
    }
    cout <<fixed <<setprecision(6) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}