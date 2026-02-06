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

const int mxn=3e5;
int n,t;

void solve() {
    cin >>n;
    vector<int> ct(n+1,0);
    rep(i,0,n) {
        int a; cin >>a;
        ct[a]++;
    }
    ll ans=0;
    ll temp=0;
    rep(i,0,n+1) {
        if(ct[i]>=2) {
            if(ct[i]>=3) {
                ans +=1ll*ct[i]*(ct[i]-1)*(ct[i]-2)/6;
            }
            ll temp2 = 1ll*ct[i]*(ct[i]-1)/2;
            temp2 *=temp;
            ans +=temp2;
        }
        temp +=ct[i];
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