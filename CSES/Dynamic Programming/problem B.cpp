#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn= 1e6, mod=1e9+7;
int n, m, t;
int a[2000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>t;
    while(t--) {
        cin >>n >>m;
        set<ar<int,2>> s;
        for(int i=0; i<n; i++) {
            cin >>a[i][0] >>a[i][1];
            s.insert({a[i][0],a[i][1]});
        }
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int d=__gcd(a[j][0]-a[i][0],a[j][1]-a[i][1]);
                int x=(a[j][0]-a[i][0])/d;
                int y=(a[j][1]-a[i][1])/d;
                int xc=a[i][0], yc=a[i][1];
                for(int k=1; k<d; k++) {
                    xc+=x;
                    yc+=y;
                    s.insert({xc,yc});
                }
            }
        }
        while(m--) {
            int r,p;
            cin >>r >>p;
            if(s.find({r,p})!=s.end())
                cout <<"YA\n";
            else
                cout <<"TIDAK\n";
        }
    }
}
