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

const int mxn=3e5;
int n,k,t;
string s;

void solve() {
    cin >>n >>k;
    cin >>s;
    int ct[2] = {0,0};
    rep(i,0,k) {
        set<char> sc;
        for(int j=i;j<sz(s);j+=k) {
            if(s[j]!='?') sc.insert(s[j]);
        }
        if(sz(sc)>1) {
            cout <<"NO\n";
            return;
        }
        if(sz(sc)) {
            ct[(*sc.begin())-'0']++;
        }
    }
    if(ct[0]>(k/2) || ct[1]>(k/2)) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
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