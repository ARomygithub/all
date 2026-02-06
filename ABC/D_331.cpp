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

const int mxn=1e3;
int n,q;
string p[mxn];
ll dp[mxn+1][mxn+1];

ll qry(int x1, int y1, int x2, int y2) {
    x1++,y1++,x2++,y2++;
    return dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1];
}

int dist(int c, int a) {
    int ret = 1;
    if((c-a)>=(n-(a%n))) {
        ret++;
        int temp = c-a;
        temp -=(n-(a%n));
        temp -=(c%n)+1;
        temp /=n;
        ret +=temp;
    }
    return ret;
}

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>p[i];
    }
    rep(i,0,n+1) {
        ll temp=0;
        rep(j,0,n+1) {
            if(i>0) {
                dp[i][j] +=dp[i-1][j];
            }            
            if(i>0 && j>0) {
                temp +=p[i-1][j-1]=='B';
            }
            dp[i][j] +=temp;
        }
    }
    while(q--) {
        int a,b,c,d; cin >>a >>b >>c >>d;
        int x1 = dist(c,a);
        int y1 = dist(d,b);
        ll ans;
        if(x1==1 && y1==1) {
            a%=n;b%=n;c%=n;d%=n;
            ans = qry(a,b,c,d);
        } else if(x1==1) {
            ll temp=d-b+1;
            a%=n;b%=n;c%=n;d%=n;
            temp -=n-b;
            temp -=d+1;
            temp /=n;
            ans = qry(a,b,c,n-1);
            ans +=temp*qry(a,0,c,n-1);
            ans +=qry(a,0,c,d);
        } else if(y1==1) {
            ll temp = c-a+1;
            a%=n;b%=n;c%=n;d%=n;
            temp -=n-a;
            temp -=c+1;
            temp /=n;
            ans = qry(a,b,n-1,d);
            ans +=temp*qry(0,b,n-1,d);
            ans +=qry(0,b,c,d);
        } else {
            ll tempx=c-a+1, tempy=d-b+1;
            a%=n;b%=n;c%=n;d%=n;
            tempx -=n-a;
            tempx -=c+1;
            tempx /=n;
            tempy -=n-b;
            tempy -=d+1;
            tempy /=n;
            // cout <<tempx <<" " <<tempy <<"\n";
            ans = qry(a,b,n-1,n-1)+qry(a,0,n-1,d)+qry(0,b,c,n-1)+qry(0,0,c,d);
            ans +=tempx*qry(0,b,n-1,n-1)+tempx*qry(0,0,n-1,d);
            ans +=tempy*qry(a,0,n-1,n-1)+tempy*qry(0,0,c,n-1);
            ans +=tempx*tempy*qry(0,0,n-1,n-1);
            // cout <<qry(0,0,n-1,n-1) <<"\n";
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}