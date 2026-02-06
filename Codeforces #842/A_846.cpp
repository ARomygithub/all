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

const int mxn=300;
int n,t;
int a[mxn+1];

void solve() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    vector<int> ans, odd, even;
    bool flag=0;
    for(int i=1;i<=n;i++) {
        if(a[i]%2) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }
    if(sz(odd)) {
        if(sz(odd)>=3) {
            cout <<"YES\n";
            cout <<odd[0] <<" " <<odd[1] <<" " <<odd[2] <<"\n";
        } else {
            if(sz(even)>=2) {
                cout <<"YES\n";
                cout <<even[0] <<" " <<even[1] <<" " <<odd[0] <<"\n";
            } else {
                cout <<"NO\n";
            }
        }
    } else {
        cout <<"NO\n";
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