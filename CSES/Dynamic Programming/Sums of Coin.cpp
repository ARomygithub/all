#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e3, mod=1e9+7;
int n, b;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>b;
    s.insert(b);
    for(int i=1; i<n; i++) {
        int a;
        cin >>a;
        set<int> s2=s;
        for(int x : s2) {
            s.insert(x+a);
        }
        s.insert(a);
    }
    cout <<s.size() <<"\n";
    for(int x : s) {
        cout <<x <<" ";
    }
}
