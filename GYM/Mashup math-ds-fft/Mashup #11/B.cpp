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
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi ct(2,0);
    rep(i,0,n) {
        ct[(a[i]%3)!=0]++;
    }
    int m = n/2;
    string s = "";
    vi cs(2,0);
    rep(i,0,n) {
        if(a[i]%3) {
            if(cs[1]==m) {
                s += '0';
                cs[0]++;
            } else {
                s += '1';
                cs[1]++;
            }
        } else {
            if(cs[0]==m) {
                s += '1';
                cs[1]++;
            } else {
                s += '0';
                cs[0]++;
            }
        }
    }
    if(ct[1]<=m) {
        cout <<"2\n";
        cout <<s <<"\n";
        return;
    }
    if(ct[0]<=m) {
        cout <<"0\n";
        cout <<s <<"\n";
        return;        
    }
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}