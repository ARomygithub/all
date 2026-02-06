#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const ll mod=1e9+7; 
const int mxn=4e5;
int t, n, a[2][mxn], p[2][mxn];

ll ct(set<int> s) {
    if(s.size()==0) {
        return 1;
    }
    ll res=0;
    set<int> t= s;
    //ambil atas
    auto i=*s.begin();
    int is = i;
    while(p[0][i]!=is) {
        s.erase(i);
        i = p[0][i];
    }
    s.erase(i);
    i =*t.begin();
    is = i;
    while(p[1][i]!=is) {
        t.erase(i);
        i = p[1][i];
    }
    t.erase(i);
    res = (ct(t) + ct(s))%mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >>t;
    while(t--) {
        cin >>n;
        set<int> s;
        for(int i=0;i<n;i++) {
            cin >>a[0][i]; a[0][i]--;
            s.insert(i);
        }
        for(int i=0;i<n;i++) {
            cin >>a[1][i]; a[1][i]--;
        }
        for(int i=0;i<n;i++) {
            p[0][a[0][i]]=a[1][i];
            p[1][a[1][i]]=a[0][i];
        }
        cout <<ct(s) <<"\n";        
    }
}   