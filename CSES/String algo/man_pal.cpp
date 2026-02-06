#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e6;
int n, p[2*mxn+3];
string s;
char c[2*mxn+3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cout.tie(0);
    cin >>s;
    n = s.size();
    c[0]='!';
    c[1]='*';
    for(int i=0;i<(int)s.size();i++) {
        c[2*i+2]=s[i];
        c[2*i+3]='*';
    }
    c[2*n+2]='@';
    int d=0;
    for(int i=1;i<=2*n+2;i++) {
        if(i<=d+p[d]) p[i]=min(p[2*d-i],d+p[d]-i);
        while(c[i-p[i]]==c[i+p[i]]) p[i]++;
        p[i]--;
        if(i+p[i]>d+p[d]) d=i;
    }
    ar<int,2> ans{0};
    for(int i=1;i<=2*n+2;i++) {
        ans = max(ar<int,2>{p[i],(i-p[i])/2},ans);
    }
    for(int i=ans[1];i<ans[1]+ans[0];i++) {
        cout <<s[i];
    }
}
