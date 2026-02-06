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

const int mxn=1e5;
int n,t;

void solve() {
    cin >>n;
    string s; cin >>s;
    int lwr=0, ctSama=0;
    bool odd=(n%2);
    for(int i=0;i<n-i-1;i++) {
        if(s[i]==s[n-i-1]) {
            ctSama++;
        } else {
            lwr++;
            // cout <<"lwr\n";
        }
    }
    vector<int> ans(n+1,0);
    if(odd) {
        for(int i=lwr;i<=lwr+ctSama*2+1;i++) {
            ans[i] = 1;
        }
    } else {
        for(int i=lwr;i<=lwr+ctSama*2;i+=2) {
            ans[i] = 1;
        }
    }
    for(int i=0;i<=n;i++) {
        cout <<ans[i];
    }
    cout <<"\n";
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