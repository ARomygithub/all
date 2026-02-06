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

const int mxn=1e6;
int n,m;
pair<string,int> s[mxn];

void solve() {
    cin >>n >>m;
    for(int i=1;i<=n;i++) {
        cin >>s[i-1].fi;
        s[i-1].se = i;
    }
    for(int i=0;i<n;i++) {
        for(int j=1;j<s[i].fi.length();j+=2) {
            s[i].fi[j] = (char)('A'+'Z'-s[i].fi[j]);
        }
    }
    sort(s,s+n);
    for(int i=0;i<n;i++) {
        if(i==0) {
            cout <<s[i].se;
        } else {
            cout <<" " <<s[i].se;
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}