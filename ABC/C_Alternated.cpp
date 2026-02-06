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

const int mxn=5e5;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vi va,vb;
    rep(i,0,n*2) {
        if(s[i]=='A') {
            va.push_back(i+1);
        } else {
            vb.push_back(i+1);
        }
    }
    ll s1 = 0;
    rep(i,0,n) {
        s1 += max(0, va[i]-2*(i+1)+1);
        s1 += max(0, vb[i]-2*(i+1));
    }
    ll s2 = 0;
    rep(i,0,n) {
        s2 += max(0, va[i]-2*(i+1));
        s2 += max(0, vb[i]-2*(i+1)+1);
    }
    cout <<min(s1,s2) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}