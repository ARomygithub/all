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

const int mxn=1e2;
int n;
string s[mxn];

void solve() {
    cin >>n;
    int m = 0;
    rep(i,0,n) {
        cin >>s[i];
        max_self(m, sz(s[i]));
    }
    vector<string> t(m,"");
    per(i,n-1,-1) {
        int k = n-i-1;
        rep(j,0,sz(s[i])) {
            while(sz(t[j])<k) {
                t[j] +='*';
            }
            t[j] += s[i][j];
        }
    }
    rep(i,0,m) {
        cout <<t[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}