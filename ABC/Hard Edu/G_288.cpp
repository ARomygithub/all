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

const int mxn=12;
int n;

void solve() {
    cin >>n;
    vector<int> s3(n+1,1);
    rep(i,1,n+1) {
        s3[i] = s3[i-1]*3;
    }
    vector<int> d(s3[n]);
    rep(i,0,s3[n]) {
        cin >>d[i];
    }
    rep(i,0,n) {
        rep(j,0,s3[n]) {
            if((j/s3[i])%3 == 0) {
                int x = j, y = j+s3[i], z = y+s3[i];
                int d2x = d[y]-d[z];
                int d2z = d[y]-d[x];
                int d2y = d[x]+d[z]-d[y];
                d[x] = d2x;
                d[y] = d2y;
                d[z] = d2z;
            }
        }
    }
    rep(i,0,s3[n]) {
        cout <<d[i] <<" \n"[i==s3[n]-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}