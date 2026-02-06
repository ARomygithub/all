#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 2e5;
int n, a[mxn], ct=0;
ll s=0;
vector<int> v;
int ans[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n;
    for(int i=0; i<n; i++) {
        cin >>a[i];
        s+=a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    auto it =--v.end();
    int l1=*it;
    --it;
    int l2=*it;
    int temp=0;
    for(int i=0; i<n; i++) {
        if(a[i]==l1) {
            if(s-a[i]-l2==l2) {
                ++ct;
                ans[temp]=i;
                ++temp;
            }
        }
        else {
            if(s-a[i]-l1==l1) {
                ++ct;
                ans[temp]=i;
                ++temp;
            }
        }
    }
    if(ct>0) {
        cout <<ct <<"\n";
        for(int i=0; i<ct; i++) {
            cout <<ans[i]+1 <<" ";
        }
    }
    else {
        cout <<"0\n";
    }
}
