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
int n;
int a[mxn];

void solve() {
    string s; getline(cin,s);
    stringstream ss(s);
    n = 0;
    while(ss >>a[n]) {
        n++;
    }
    vector<int> v;
    for(int i=0;i<n;) {
        int j=i+1;
        while(j<n && a[j]==a[i] && j<i+255) {
            j++;
        }
        v.push_back(j-i);
        v.push_back(a[i]);
        i = j;
    }
    cout <<sz(v) <<"\n";
    for(int i=0;i<sz(v);i++) {
        cout <<v[i] <<" \n"[i==sz(v)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}