#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 2e5;
int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++) {
        int a;
        cin >>a;
        auto it= lower_bound(v.begin(),v.end(),a);
        if(it!=v.end())
            *it=a;
        else
            v.push_back(a);
    }
    cout <<v.size();
}
