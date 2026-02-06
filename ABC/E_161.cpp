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

const int mxn=2e5;
int n,k,c;
string s;

void solve() {
    cin >>n >>k >>c;
    cin >>s;
    vector<int> kiri,kanan;
    int last = -1e9;
    rep(i,0,n) {
        if(s[i]=='o') {
            if(i-last>=c+1) {
                kiri.push_back(i);
                last = i;
                if(sz(kiri)==k) break;
            }
        }
    }
    last = 1e9;
    per(i,n-1,-1) {
        if(s[i]=='o') {
            if(last-i>=c+1) {
                kanan.push_back(i);
                last = i;
                if(sz(kanan)==k) break;
            }
        }
    }
    reverse(kanan.begin(),kanan.end());
    rep(i,0,k) {
        if(kanan[i]==kiri[i]) {
            cout <<kiri[i]+1 <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}