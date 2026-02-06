#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn=3e5;
int n,k;
int d[mxn];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >>t;
    while(t--) {
        cin >>n >>k;
        priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
        int a[k];
        for(int i=0;i<k;i++) {
            cin >>a[i]; --a[i];
        }
        for(int i=0;i<k;i++) {
            int b; cin >>b;
            pq.push({b,a[i]});
        }
        memset(d,0x3f,sizeof(d));
        while(pq.size()) {
            ar<int,2> u=pq.top(); pq.pop();
            //process u
            if(u[0]>=d[u[1]])
                continue;
            else {
                d[u[1]]=u[0];
                if(u[1]>0 && d[u[1]-1]>u[0]+1) pq.push({u[0]+1,u[1]-1});
                if(u[1]<n-1 && d[u[1]+1]>u[0]+1) pq.push({u[0]+1,u[1]+1});
            }
        }
        for(int i=0;i<n;i++) {
            cout <<d[i] <<" ";
        }
        cout <<"\n";
    }
}   