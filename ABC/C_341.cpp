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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=500;
int n,m,k;
string t;
string s[mxn];

void solve() {
    cin >>n >>m >>k;
    cin >>t;
    rep(i,0,n) {
        cin >>s[i];
    }
    int ct = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            if(s[i][j]=='#') continue;
            bool ok = 1;
            int ii=i,jj=j;
            rep(l,0,k) {
                if(t[l]=='L') {
                    jj--;
                } else if(t[l]=='R') {
                    jj++;
                } else if(t[l]=='U') {
                    ii--;
                } else {
                    ii++;
                }
                ok &= s[ii][jj]!='#';
                if(!ok) break;
            }
            ct += ok;
        }
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}