#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

ll lm,rm,lb,rb;

void solve() {
    cin >>lm >>rm;
    cin >>lb >>rb;
    ll ans = 0;
    ll le = 1, ri = min((rb-lb+1)/2, rm-lm);
    while(le<=ri) {
        ll mid = (le+ri)/2;
        ll sm = mid*(rm*2-mid+1)/2 + lm*mid;
        ll sb = mid*(lb*2+mid*2-1);
        if(sm - sb >= 0) {
            ans = mid;
            le = mid+1;
        } else {
            ri = mid-1;
        }
    }   
    cout <<ans <<"\n";
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}