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
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans = 0;
    map<int,int> mp;
    int ct0 = 0;
    rep(i,0,n) {
        for(int j=2;j*j<=a[i];j++) {
            while(a[i]%(j*j)==0) {
                a[i] /=(j*j);
            }
        }
        if(a[i]!=0) {
            ans += 1ll*mp[a[i]];
            mp[a[i]]++;
            ans += 1ll*ct0;
        } else {
            ans += 1ll*i;
            ct0++;
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