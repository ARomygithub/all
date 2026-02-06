
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e4, mxm=1e5;
short int n, p[mxn];
int m;
vector<short int> cs(mxn);
bool vis[mxn];

int find(int x) {
    return x^p[x]?p[x]=find(p[x]):x;
}

void join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return;
    }
    if (cs[x]>cs[y]) swap(x,y);
    cs[y]=cs[x]+cs[y];
    p[x]=y;
    //update cs juga
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        cin >>cs[i];
    }
    iota(p,p+n,0);
    for(int i=0;i<m;i++) {
        int a,b; cin >>a >>b; a--, b--;
        join(a,b);
    }
    vector<short int> v;
    int ans=0;
    for(int i=0;i<n;i++) {
        if(!vis[find(i)]) {
            v.push_back(cs[find(i)]);
            vis[find(i)]=true;
        }
    }
    sort(v.begin(),v.end(),greater<short int>());
    for(int i=0;i<(int)v.size();i++) {
        ans += (i+1)*(int)v[i];
    }
    cout <<ans;
}