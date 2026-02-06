#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e5;
int n, q;
vector<int> v[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    if(n>2) {
        if(n%2)
            cout <<"NO\n";
        else
            cout <<"YES\n";
    }
    else
        cout <<"NO\n";
}
