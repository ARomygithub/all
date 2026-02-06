#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
int n,m;
string s,t;

void solve() {
    cin >>n >>m;
    cin >>s;
    cin >>t;
    bool suf = s==t.substr(m-n,n);
    bool pref = s==t.substr(0,n);
    if(suf && pref) {
        cout <<"0\n";
    } else if(pref) {
        cout <<"1\n";
    } else if(suf) {
        cout <<"2\n";
    } else {
        cout <<"3\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}