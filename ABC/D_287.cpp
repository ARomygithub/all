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
int n,m;
string s,t;

void solve() {
    cin >>s >>t;
    n = s.length(), m=t.length();
    int l=0, r=0;;
    for(int i=0;i<m;i++) {
        if(s[i]=='?' || t[i]=='?' || s[i]==t[i]) {
            l++;
        } else {
            break;
        }
    }
    for(int i=m-1;i>=0;i--) {
        if(s[n-m+i]=='?' || t[i]=='?' || s[n-m+i]==t[i]) {
            r++;
        } else {
            break;
        }
    }
    for(int i=0;i<=m;i++) {
        if(i>l || (m-i)>r) {
            cout <<"No\n";
        } else {
            cout <<"Yes\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}