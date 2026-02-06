#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 2e5;
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>ans;
    for(int i=0; i<3; i++) {
        int a;
        cin >>a;
        ans=max(ans,a);
    }
    cout <<ans <<"\n";
}
