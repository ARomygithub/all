#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn=1e5, mxk=18;
int k, q;
string s;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>k;
    cin >>s;
    reverse(s.begin(),s.end());
    int n=1<<k;
    vector<int> dp(2*n, 1);
    
    auto upd = [&](int i) {
        return dp[i]=(s[i]!='0'?dp[2*i+1]:0) +(s[i]!='1'?dp[2*i+2]:0);
    };

    cin >>q;
    for(int i=n-2;i>=0;i--) {
        upd(i);
    }
    while(q--) {
        int p; char c; cin >>p >>c;
        p = n-1-p;
        s[p]=c;
        while(p) {
            upd(p);
            p = (p-1)/2;
        }
        cout <<upd(0) <<"\n";
    }
}   