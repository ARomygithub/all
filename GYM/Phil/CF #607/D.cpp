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

const int mxn=60;
int n,m,t;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    int cta=0,ctb=0,ctc=0;
    int hf=mxn,hl=-1,vf=mxn,vl=-1;
    rep(i,0,n) {
        rep(j,0,m) {
            cta +=s[i][j]=='A';
            if(i==0 || i==n-1 || j==0 || j==m-1) {
                ctb +=s[i][j]=='A';
            }
            if((i==0 || i==n-1) && (j==0 || j==m-1)) {
                ctc +=s[i][j]=='A';
            }
        }
    }
    rep(i,0,n) {
        bool flag=1;
        rep(j,0,m) {
            flag &=s[i][j]=='A';
        }
        if(flag) {
            min_self(hf,i);
            max_self(hl,i);
        }
    }
    rep(j,0,m) {
        bool flag=1;
        rep(i,0,n) {
            flag &=s[i][j]=='A';
        }
        if(flag) {
            min_self(vf,j);
            max_self(vl,j);
        }
    }
    if(cta==n*m) {
        cout <<"0\n";
    } else if(hf==0 || hl==n-1 || vf==0 || vl==m-1) {
        cout <<"1\n";
    } else {
        if(hf<n || vf<m || ctc>0) {
            cout <<"2\n";
        } else if(ctb>0) {
            cout <<"3\n";
        } else if(cta>0) {
            cout <<"4\n";
        } else {
            cout <<"MORTAL\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}