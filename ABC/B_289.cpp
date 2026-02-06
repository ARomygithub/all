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
int n,m;
stack<int> s;
int a[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        cin >>a[i];
    }
    bool first=1;
    for(int i=1,j=0;i<=n;i++) {
        while(j<m && i==a[j]) {
            s.push(i);
            j++; i++;
        }
        s.push(i);
        while(sz(s)) {
            if(first) {
                cout <<s.top(); s.pop();
                first = 0;
            } else {
                cout <<" " <<s.top(); s.pop();
            }
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