#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,a,b;
string s;

void solve() {
    cin >>n >>a >>b;
    cin >>s;
    s +=s;
    ll ans=1e18;
    for(int i=0;i<n;i++) {
        ll temp=1ll*a*i;
        for(int j=0;j<n-1-j;j++) {
            if(s[i+j]!=s[i+n-1-j]) {
                temp +=b;
            }
        }
        min_self(ans,temp);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}