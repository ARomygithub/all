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

const int mxn=50;
int n,m, si, sj;
string c[mxn], x;

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&c[i][j]=='.';
}

void solve() {
    cin >>n >>m;
    cin >>si >>sj; si--,sj--;
    rep(i,0,n) {
        cin >>c[i];
    }
    cin >>x;
    rep(i,0,sz(x)) {
        if(x[i]=='L' && e(si,sj-1)) {
            sj--;
        } else if(x[i]=='R' && e(si,sj+1)) {
            sj++;
        } else if(x[i]=='U' && e(si-1,sj)) {
            si--;
        } else if(x[i]=='D' && e(si+1,sj)) {
            si++;
        }
    }
    cout <<si+1 <<" " <<sj+1 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}