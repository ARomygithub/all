#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=100;
int n,m,k;
string file_out;
char puzzle[mxn][mxn];
string word[mxn];

void solve() {
    const char* fo = file_out.c_str();
    freopen(fo,"w",stdout);
    cin >>n >>m >>k;
    char c;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>puzzle[i][j];
        }
    }
    for(int i=0;i<k;i++) {
        cin >>word[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(j==0) {
                cout <<puzzle[i][j];
            } else {
                cout <<" " <<puzzle[i][j];
            }
        }
        cout <<"\n";
    }
    cout <<"\n";
    for(int i=0;i<k;i++) {
        cout <<word[i] <<"\n";
    }
}

int main() {
    while(cin >>file_out) {
        solve();
    }
}
