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

const int mxn=1e2;
int n,m,k,t;
string s[mxn];

pii nxt(pii u) {
    if(u.fi%2) {
        if(u.se==0) {
            return {u.fi+1,0};
        } else {
            return {u.fi,u.se-1};
        }
    } else {
        if(u.se==m-1) {
            return {u.fi+1,m-1};
        } else {
            return {u.fi,u.se+1};
        }
    }
}

void solve() {
    cin >>n >>m >>k;
    int ct = 0;
    rep(i,0,n) {
        cin >>s[i];
        rep(j,0,m) {
            ct += (s[i][j]=='R');
        }
    }
    int atas = ct%k;
    pii u = {0,0};
    vector<char> cc;
    rep(i,0,26) {
        cc.push_back((char)('A'+i));
    }  
    rep(i,0,26) {
        cc.push_back((char)('a'+i));
    }
    rep(i,0,10) {
        cc.push_back((char)('0'+i));
    }
    vector ans(n, vector<char>(m));
    int i=0;
    int cti;
    if(atas>0) {
        cti = (ct/k)+1;
    } else {
        cti = (ct/k);
    }
    while(u.fi<n) {
        ans[u.fi][u.se] = cc[i];
        if(s[u.fi][u.se]=='R') {
            cti--;
            if(cti==0) {
                if(i+1<k) {
                    i++;
                    atas--;
                    cti = ct/k;
                    if(atas>0) cti++;
                }
            }
        }
        u = nxt(u);
    }
    rep(i,0,n) {
        rep(j,0,m) {
            cout <<ans[i][j];
        }
        cout <<"\n";
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