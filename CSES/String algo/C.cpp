#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n, l1, r1, l2, r2;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    int t; cin >>t;
    while(t--) {
        cin >>n;
        cin >>s;
        int l=n/2;
        bool flag=false;
        for(int i=s.length()-1;i>=l;i--) {
            if(s[i]=='0') {
                flag=true;
                r1=i;
            }
        }
        if(flag) {
            l1=0, l2=0, r2=r1-1;
            cout <<l1+1 <<" " <<r1+1 <<" " <<l2+1 <<" " <<r2+1 <<"\n";
        } else {
            if(n%2) {
                l1=l+1; r1=n-1; l2=l+2; r2=n;
                cout <<l1 <<" " <<r1 <<" " <<l2 <<" " <<r2 <<"\n";
            } else {
                if(s[l-1]=='1') {
                    l1=l-1, r1=n-2, l2=l, r2=n-1;
                    cout <<l1+1 <<" " <<r1+1 <<" " <<l2+1 <<" " <<r2+1 <<"\n";
                } else {
                    l1=l-1, r1=n-1, l2=l, r2=n-1;
                    cout <<l1+1 <<" " <<r1+1 <<" " <<l2+1 <<" " <<r2+1 <<"\n";                    
                }
            }
        }
    }
}
