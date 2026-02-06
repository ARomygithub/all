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

const int mxn=1e2;
int n,t;
string s;

void solve() {
    cin >>s;
    n = s.length();
    for(int i=1;i<n-1;i++) {
        if(s[i]=='a') {
            cout <<s.substr(0,i) <<" a " <<s.substr(i+1,n-i-1) <<"\n";
            return;
        }
    }
    cout <<s[0] <<" " <<s.substr(1,n-2) <<" " <<s[n-1] <<'\n'; 
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