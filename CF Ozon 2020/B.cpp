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

const int mxn=1e5;
int n;
string s;

void solve() {
    cin >>s;
    n = s.length();
    vector<int> l,r;
    int il=0;
    while(il<n && s[il]!='(') {
        il++;
    }
    int ir=n-1;
    while(ir>=0 && s[ir]!=')') {
        ir--;
    }
    while(il<ir) {
        l.push_back(il);
        r.push_back(ir);
        il++,ir--;
        while(il<n && s[il]!='(') {
            il++;
        }        
        while(ir>=0 && s[ir]!=')') {
            ir--;
        }    
    }
    if(sz(l)>0) {
        cout <<"1\n";
        cout <<sz(l)+sz(r) <<"\n";
        rep(i,0,sz(l)) {
            cout <<l[i]+1 <<" ";
        }
        reverse(r.begin(),r.end());
        rep(i,0,sz(r)) {
            cout <<r[i]+1 <<" \n"[i==sz(r)-1];
        }
    } else {
        cout <<"0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}