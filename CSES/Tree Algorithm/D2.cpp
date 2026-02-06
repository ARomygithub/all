
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e3;
int n,m1, m2, p1[mxn], p2[mxn], ct1, ct2;
vector<int> cs1(mxn,1), cs2(mxn,1);

int find1(int x) {
    return x^p1[x]?p1[x]=find1(p1[x]):x;
}
int find2(int x) {
    return x^p2[x]?p2[x]=find2(p2[x]):x;
}

bool join1(int x, int y) {
    if((x=find1(x))==(y=find1(y))) {
        return 0;
    }
    if (cs1[x]>cs1[y]) swap(x,y);
    cs1[y]=cs1[x]+cs1[y];
    p1[x]=y;
    ct1--;
    return 1;
    //update cs juga
}
bool join2(int x, int y) {
    if((x=find2(x))==(y=find2(y))) {
        return 0;
    }
    if (cs2[x]>cs2[y]) swap(x,y);
    cs2[y]=cs2[x]+cs2[y];
    p2[x]=y;
    ct2--;
    return 1;
    //update cs juga
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>m1 >>m2;
    bool ok;
    iota(p1,p1+n,0);
    ct1=n, ct2=n;    
    for(int i=0;i<m1;i++) {
        int a,b; cin >>a >>b; a--, b--;
        ok = join1(a,b);
    }
    iota(p2,p2+n,0);
    for(int i=0;i<m2;i++) {
        int a,b; cin >>a >>b; a--, b--;
        ok = join2(a,b);
    }
    vector<ar<int,2>> ans;
    for(int i=0;i<n;i++) {
        int a = find1(i);
        int b = find2(i);
        if(find1(a)!=find1(b) && find2(a)!=find2(b)) {
            ok = join1(a,b) && join2(a,b);
            ans.push_back({a,b});
        }
    }
    set<int> s;
    if(ct2<=ct1) {
        for(int i=0;i<n;i++) {
            s.insert(find2(i));
        }
    } else {
        for(int i=0;i<n;i++) {
            s.insert(find1(i));
        }
    }
    for(auto i=s.begin(),j=++s.begin();j!=s.end();i++,j++) {
        ans.push_back({*i,*j});
    }
    cout <<ans.size() <<"\n";
    for(auto u : ans) {
        cout <<u[0]+1 <<" " <<u[1]+1 <<"\n";
    }    
}