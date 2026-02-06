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
string s;

void solve() {
    cin >>n;
    cin >>s;
    int ct1=0;
    vector<int> v;
    rep(i,0,n) {
        if(s[i]=='1') {
            ct1++;
            v.push_back(i);
        }
    }
    if(ct1%2) {
        cout <<"NO\n";
    } else {
        if(sz(v)==2 && v[1]==v[0]+1) {
            cout <<"NO\n";
        } else {
            cout <<"YES\n";
        }
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