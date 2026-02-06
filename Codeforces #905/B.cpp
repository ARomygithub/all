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
int n,k,t;
int a[mxn];

void solve() {
    cin >>n >>k;
    vector<int> ct(k,0);
    int u=k;
    rep(i,0,n) {
        cin >>a[i];
        ct[a[i]%k]++;
        u /=__gcd(u,a[i]);
    }
    if(k==4) {
        if(u==1) {
            cout <<"0\n";
            return;
        } else {
            int mx=4;
            rep(i,0,4) {
                if(ct[i]) {
                    min_self(mx, 4-(i%4));
                }
            }
            min_self(mx, 2-ct[2]);
            cout <<mx <<"\n";
            return;
        }
    }
    if(u==1) {
        cout <<"0\n";
        return;
    } else {
        int mx=k;
        rep(i,0,k) {
            if(ct[i]) {
                min_self(mx,k-(i%k));
            }
        }
        cout <<mx <<"\n";
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