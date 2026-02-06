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

const int mxn=1e5;
int n,t;

void solve() {
    cin >>n;
    vector<string> v(n);
    rep(i,0,n) {
        cin >>v[i];
    }
    set<int> s;
    rep(i,0,n) {
        int idx = 0;
        int a = 0;
        while(v[i][idx]!='e') {
            a = a*10 + (v[i][idx]-'0');
            idx++;
        }
        idx++;
        s.insert(a);
        a = 0;
        while(idx<sz(v[i])) {
            a = a*10 + (v[i][idx]-'0');
            idx++;
        }
        s.insert(a);
    }
    if(sz(s)==n*2) {
        cout <<"VALID\n";
    } else {
        cout <<"INVALID\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}