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
int n, a[2],b[2],c[2];

int sgn(int x) {
    return (x>=0)-(x<=0);
}

void solve() {
    cin >>n;
    cin >>a[0] >>a[1];
    cin >>b[0] >>b[1];
    cin >>c[0] >>c[1];
    if(sgn(b[0]-a[0])==sgn(c[0]-a[0]) && sgn(b[1]-a[1])==sgn(c[1]-a[1])) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}