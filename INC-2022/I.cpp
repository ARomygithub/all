#include "bits/stdc++.h"
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
int n,q;
string s;

void solve() {
    cin >>n;
    int block = ceil(sqrt(n));
    cin >>s;
    cin >>q;
    vector<vector<int>> v(block+1);
    for(int i=1;i<=block;i++) {
        v[i] = vector<int>(i,0);
    }
    // cout <<v[1][0] <<"\n";
    for(int i=1;i<=block;i++) {
        for(int j=0;j<n;j++) {
            if(s[j]=='0') {
                v[i][(j+1)%i]++;
            }
        }
    }
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x; cin >>x;
            for(int i=1;i<=block;i++) {
                v[i][(x)%i]--;
            }
            s[x-1] = '1';
        } else if(qt==2) {
            int x; cin >>x;
            for(int i=1;i<=block;i++) {
                v[i][(x)%i]++;
            }
            s[x-1] = '0';
        } else {
            int x,k; cin >>x >>k;
            if(k<=block) {
                cout <<v[k][(x)%k] <<"\n";
            } else {
                int ans=0;
                for(int i=x-1;i<n;i+=k) {
                    if(s[i]=='0') {
                        ans++;
                    }
                }
                cout <<ans <<"\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}