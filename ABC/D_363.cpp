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
ll n;

void solve() {
    cin >>n;
    if(n<=10) {
        cout <<n-1 <<"\n";
        return;
    }
    n -= 10;
    if(n<=9) {
        cout <<n <<n <<"\n";
        return;
    }
    n -= 9;
    int dig = 2;
    ll mul = 9*10;
    while(n > mul*2) {
        n -= mul*2;
        dig++;
        mul *=10ll;
    }
    if(n>mul) {
        n -= mul;
        ll awl = 1;
        rep(i,0,dig-1) {
            awl *=10ll;
        }
        awl = awl-1+n;
        string ans = to_string(awl);
        string rev = ans; reverse(rev.begin(),rev.end());
        ans = ans+rev;
        cout <<ans <<"\n";
    } else {
        ll awl = 1;
        rep(i,0,dig-1) {
            awl *= 10ll;
        }
        awl = awl-1+n;
        string ans = to_string(awl);
        string rev = ans.substr(0,sz(ans)-1); reverse(rev.begin(),rev.end());
        ans = ans+rev;
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}