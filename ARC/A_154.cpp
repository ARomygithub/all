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

const int mxn=2e5;
const ll mod=998244353;
int n;
string a,b;

void solve() {
    cin >>n;
    cin >>a >>b;
    ll ai=0,bi=0;
    for(int i=0;i<n;i++) {
        if(a[i]>b[i]) swap(a[i],b[i]);
        ai = (ai*10+(a[i]-'0'))%mod;
        bi = (bi*10+(b[i]-'0'))%mod;
    }
    ai = ai*bi%mod;
    cout <<ai <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}