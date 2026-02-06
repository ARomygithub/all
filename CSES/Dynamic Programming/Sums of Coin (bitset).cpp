#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5, mod=1e9+7;
int n;
bitset<mxn+1> bs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    bs[0]=1;
    for(int i=0; i<n; i++) {
        int a;
        cin >>a;
        bs|=(bs<<a);
    }
    cout <<bs.count()-1 <<"\n";
    for(int i=1; i<=mxn; i++) {
        if(bs[i])
            cout <<i <<" ";
    }
}
