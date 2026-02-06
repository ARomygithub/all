#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n;
string s,t;

void solve() {
    cin >>n;
    cin >>s >>t;
    vector<int> a,b;
    rep(i,0,n) {
        if(s[i]!=t[i]) {
            if(t[i]=='A') {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
    }
    if((sz(a)>0 && a[sz(a)-1]==n-1) || (sz(b)>0 && b[0]==0)) {
        cout <<"-1\n";
        return;
    }
    if(sz(a)>0) {
        bool flag=0;
        rep(i,a[sz(a)-1],n) {
            flag |=(t[i]=='B');
        }
        if(!flag) {
            cout <<"-1\n";
            return;
        }
    }
    if(sz(b)>0) {
        bool flag=0;
        rep(i,0,b[0]) {
            flag |=(t[i]=='A');
        }
        if(!flag) {
            cout <<"-1\n";
            return;
        }
    }
    int ans=0;
    int ida=0,idb=0;
    while(ida<sz(a) && idb<sz(b)) {
        while(idb<sz(b) && a[ida]>b[idb]) {
            ans++;
            idb++;
        } 
        ans++;
        ida++;
        idb++;
    }
    if(ida<sz(a)) {
        ans +=sz(a)-ida;
    }
    if(idb<sz(b)) {
        ans +=sz(b)-idb;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}