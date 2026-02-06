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

const int mxn=2e5;
const ll mod = 998244353;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi ad;
    rep(i,0,n) {
        int cur = a[i] - (i>0?a[i-1]:0);
        if(cur<0) {
            cout <<"0\n";
            return;
        }
        rep(j,0,cur) {
            ad.push_back(i);
        }
    }
    if(sz(ad)!=n) {
        cout <<"0\n";
        return;
    }
    ll ans = 1;
    ll sv = 0, sp=0;
    for(int i=0;i<n;) {
        int dif = ad[i] - (i>0?ad[i-1]: -1);
        sv += dif;
        sp += (i>0?dif:dif-1);
        int j = i;
        while(j<n && ad[j]==ad[i]) {
            j++;
        }
        if(j-i>2) {
            cout <<"0\n";
            return;
        } else if(j-i==2) {
            ans = ans*(sv-1)%mod;
            ans = ans*sp%mod;
            sv -= 2;
            sp -= 2;
        } else if(j-i==1) {
            ans = ans*(sv+sp)%mod;
            sv -= 1;
            sp -= 1;
        }
        i = j;
    }
    cout <<ans <<"\n";
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