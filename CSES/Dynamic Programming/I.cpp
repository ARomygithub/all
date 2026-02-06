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
    cin >>n >>q;
    for(int i=0; i<n; i++) {
        int k;
        cin >>k;
        for(int j=0; j<k; j++) {
            int l;
            cin >>l;
            v[i].push_back(l);
        }
    }
    while(q--) {
        int a,b;
        cin >>a >>b;
        cout <<v[a][b] <<"\n";
    }
}
