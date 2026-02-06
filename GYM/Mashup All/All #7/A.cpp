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
int n,m;
string s,t;

void solve() {
    cin >>n >>m;
    cin >>s;
    cin >>t;
    int x = -1;
    rep(i,0,n) {
        if(s[i]=='*') {
            x = i;
            break;
        }
    }
    bool ok = 1;
    if(x==-1) {
        ok = s==t;
    } else {
        ok = (n-1<=m);
        rep(i,0,x) {
            ok = ok && s[i]==t[i];
        }
        rep(i,x+1,n) {
            ok = ok && s[i]==t[m - (n-i)];
        }
    }
    if(ok) {
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