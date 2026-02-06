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
int v[mxn],d[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>v[i] >>d[i];
    }
    double ans = 1.0*d[0]/v[0];
    int id = 0;
    rep(i,1,n) {
        double tmp = 1.0*d[i]/v[i];
        if(tmp< ans) {
            ans = tmp;
            id = i;
        }
    }
    cout <<id+1 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}