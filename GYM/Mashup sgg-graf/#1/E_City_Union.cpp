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
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=50;
int n,m,t;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    int ls = -1;
    int l,r;
    rep(i,0,n) {
        int li = -1, ri =-1;
        rep(j,0,m) {
            if(s[i][j]=='#') {
                if(li==-1) li = j;
                ri = j;
            }
        }
        if(li!=-1) {
            if(ls!=-1 && ls!=i-1) {
                int mid = clamp(li, l, r);
                rep(i1,ls,i+1) {
                    s[i1][mid] = '#';
                }
            }
            ls = i;
            l = li, r = ri;
        }
    }
    ls = -1;
    rep(j,0,m) {
        int li = -1, ri = -1;
        rep(i,0,n) {
            if(s[i][j]=='#') {
                if(li==-1) li = i;
                ri = i;
            }
        }
        if(li!=-1) {
            if(ls!=-1 && ls!=j-1) {
                int mid = clamp(li,l,r);
                rep(j1,ls,j+1) {
                    s[mid][j1] = '#';
                }
            }
            ls = j;
            l = li, r = ri;
        }
    }
    rep(i,0,n) {
        int li = -1, ri =-1;
        rep(j,0,m) {
            if(s[i][j]=='#') {
                if(li==-1) li = j;
                ri = j;
            }
        }
        if(li!=-1) {
            rep(j,li,ri+1) {
                s[i][j] = '#';
            }
        }
    }
    rep(j,0,m) {
        int li = -1, ri = -1;
        rep(i,0,n) {
            if(s[i][j]=='#') {
                if(li==-1) li = i;
                ri = i;
            }
        }
        if(li!=-1) {
            rep(i,li,ri+1) {
                s[i][j] = '#';
            }
        }                
    }
    rep(i,0,n) {
        cout <<s[i] <<"\n";
    }
    cout <<"\n";
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