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

const int mxn=1e5;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    ll ans = 0;
    for(int i=0;i<n-1;) {
        ll pr = 0;
        ll cur = 1;
        while(i<n-1 && s[i]!='>') {
            if(s[i] == '=') {
                cur++;
                ans += pr;
            } else {
                pr += cur;
                cur = 1;
                ans += pr;
            }
            i++;
        }
        i++;
    }
    for(int i=0;i<n-1;) {
        ll pr = 0;
        ll cur = 1;
        while(i<n-1 && s[i]!='<') {
            if(s[i] == '=') {
                cur++;
                ans += pr;
            } else {
                pr += cur;
                cur = 1;
                ans += pr;
            }
            i++;
        }
        i++;
    }    
    cout <<ans <<"\n";
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