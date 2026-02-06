#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int a,b,p,m,x,y;
int s2;

int f(int mid) {
    int s3=m*min(b*mid,y);
    int cur= x-a*mid;
    int temp=0;
    if(s2>s3) {
        if(cur>0) {
            if(cur>s2) {
                if(s3>0) {
                    temp = (cur-s2+s3-1)/s3;
                    temp++;
                } else {
                    temp=(int)1e9;
                }
            } else {
                temp=1;
            }
        }
    } else {
        if(cur>0) {
            temp = (cur+s3-1)/s3;
        }
    }
    return temp+mid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >>t;
    while(t--) {
        cin >>a >>b >>p >>m;
        cin >>x >>y;
        int l=1, r=(x+a-1)/a;
        s2=p*x/100;
        int ans=r;
        while(l<=r) {
            int z=(l+r)/2;
            if(f(z)<=f(z+1)) {
                ans=f(z);
                r=z-1;
            } else {
                l=z+1;
            }
        }
        cout <<(s2>=x?1:ans) <<"\n";
    }
}
