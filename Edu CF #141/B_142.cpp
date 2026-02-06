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
int a,b,c,d,t;

void solve() {
    cin >>a >>b >>c >>d;
    int ans=a;
    if(a>0) {
        ans +=min(b,c)*2;
        ans +=min(a+1,max(b,c)-min(b,c)+d);
        cout <<ans <<"\n";
    } else {
        if(b+c+d>0) {
            cout <<a+1 <<"\n";
        } else {
            cout <<"0\n";
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