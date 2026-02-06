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

const int mxn=1e5;
int n,m,x,y;
int t[mxn],k[mxn];

void solve() {
    cin >>n >>m >>x >>y;
    rep(i,0,m) {
        cin >>t[i] >>k[i];
    }
    ll ans = 0;
    int i=0,j=0;
    while(i<m && t[i]!=1) {
        i++;
    }
    while(j<m && t[j]!=2) {
        j++;
    }
    while(i<m || j<m) {
        if(i<j) {
            int mv = abs(x-k[i]);
            ans += mv;
            x = k[i];
            if(j<m) {
                int omv = min(abs(y-k[j]),mv);
                if(y<=k[j]) {
                    y += omv;
                } else {
                    y -= omv;
                }
            }
            i++;
            while(i<m && t[i]!=1) {
                i++;
            }            
        } else {
            int mv = abs(y-k[j]);
            ans += mv;
            y = k[j];
            if(i<m) {
                int omv = min(abs(x-k[i]),mv);
                if(x<=k[i]) {
                    x += omv;
                } else {
                    x -= omv;
                }
            }
            j++;
            while(j<m && t[j]!=2) {
                j++;
            }            
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}