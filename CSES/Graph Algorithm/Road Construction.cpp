#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5;
int n,m, p[mxn];
vector<int> cs(mxn,1);
ar<int,2> e[mxn];

int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return 0;
    }
    cs[y]=cs[x]+cs[y];
    p[x]=y;
    return 1;
    //update cs juga
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        cin >>e[i][0] >>e[i][1]; --e[i][0], --e[i][1];
    }
    int ct=n; int cmax=1;
    iota(p,p+n,0);
    for(int i=0;i<m;i++) {
        if(join(e[i][0],e[i][1])) {
            ct--;
            cmax= max(cmax,cs[find(e[i][0])]);
            //blm connected terus diconnectin
        }
        cout <<ct <<" " <<cmax <<"\n";
    }
}