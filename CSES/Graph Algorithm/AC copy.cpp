#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn=3e5;
int d=1;
double c,m,p,v, ans=0, pr=1.0;

void dfs()
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >>t;
    while(t--) {
        cin >>c >>m >>p >>v;
        dfs(c,m,p,v,pr,d);
    }
}   