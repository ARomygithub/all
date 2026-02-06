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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e3;
int n;
int a[mxn];

void solve() {
    cin >>n;
    set<int> s;
    rep(i,0,n) {
        cin >>a[i];
        s.insert(a[i]);
    }
    if(sz(s)==1) {
        cout <<"SESUAI\n";
    } else if(sz(s)==2) {
        if(n==2) {
            int mn,mx,imn,imx;
            if(a[0]<=a[1]) {
                mn = a[0], imn=0;
                mx = a[1], imx=1;
            } else {
                mn = a[1], imn=1;
                mx= a[0], imx=0;
            }
            if((mn+mx)%2) {
                cout <<"TIDAK SESUAI\n";
            } else {
                cout <<(mx-mn)/2 <<" " <<imx+1 <<" " <<imn+1 <<"\n";
            }
        } else {
            cout <<"TIDAK SESUAI\n";
        }
    } else if(sz(s)==3) {
        auto it = s.begin(); it++;
        int mn = *s.begin();
        int md = *it; it++;
        int mx = *it;
        int ct = 0;
        int imn,imx;
        rep(i,0,n) {
            ct += a[i]==md;
            if(a[i]==mn) imn=i;
            if(a[i]==mx) imx=i;
        }
        if(mn+mx==md*2 && ct==n-2) {
            cout <<(mx-mn)/2 <<" " <<imx+1 <<" " <<imn+1 <<"\n";
        } else {
            cout <<"TIDAK SESUAI\n";
        }
    } else {
        cout <<"TIDAK SESUAI\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}