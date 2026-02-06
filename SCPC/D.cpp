#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()

const int mxn=1e5;
int x,y,n;
int l,r,d,u;

pair<int,char> ask(int x1, int y1) {
    cout <<"? " <<x1 <<" " <<y1 <<"\n";
    cout <<flush;
    int qt; char c;
    cin >>qt >>c;
    return {qt,c};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>x >>y >>n;
    l=0, r=x, d=0, u=y;
    for(int i=0;i<n && ((r-l)>1 || (u-d)>1);i++) {
        pair<int,char> p =ask((l+r)/2,(d+u)/2);
        if(p.first==1) {
            l= (l+r)/2, d=(d+u)/2;
            if(p.second=='U') {
                u = min(u+1,y);
                d = min(d+1,y);
            } else if(p.second=='L') {
                l = max(l-1,0);
                r = max(r-1,0);
            } else if(p.second=='D') {
                d = max(0,d-1);
                u = max(0,u-1);
            } else if(p.second=='R') {
                r = min(r+1,x);
                l = min(l+1,x);
            }
        } else if(p.first==2) {
            r = (l+r)/2, d=(d+u)/2;
            if(p.second=='U') {
                u = min(u+1,y);
                d = min(d+1,y);
            } else if(p.second=='L') {
                l = max(l-1,0);
                r = max(r-1,0);
            } else if(p.second=='D') {
                d = max(0,d-1);
                u = max(0,u-1);
            } else if(p.second=='R') {
                r = min(r+1,x);
                l = min(l+1,x);
            }            
        } else if(p.first==3) {
            r = (l+r)/2, u=(d+u)/2;
            if(p.second=='U') {
                u = min(u+1,y);
                d = min(d+1,y);
            } else if(p.second=='L') {
                l = max(l-1,0);
                r = max(r-1,0);
            } else if(p.second=='D') {
                d = max(0,d-1);
                u = max(0,u-1);
            } else if(p.second=='R') {
                r = min(r+1,x);
                l = min(l+1,x);
            }          
        } else if(p.first==4) {
            l = (l+r)/2, u = (d+u)/2;
            if(p.second=='U') {
                u = min(u+1,y);
                d = min(d+1,y);
            } else if(p.second=='L') {
                l = max(l-1,0);
                r = max(r-1,0);
            } else if(p.second=='D') {
                d = max(0,d-1);
                u = max(0,u-1);
            } else if(p.second=='R') {
                r = min(r+1,x);
                l = min(l+1,x);
            }          
        }
    }
    if(u==d) u++;
    if(r==l) r++;
    cout <<"! " <<r <<" " <<u <<"\n";
    cout <<flush;
    return 0;
}
