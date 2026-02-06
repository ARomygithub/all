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

const int mxn=1e5;
ll a,m,x;

ll fastexpo(ll ai, ll bi, ll mi) {
    ll ret = 1;
    // assert(bi>0);
    while(bi) {
        if(bi&1) ret = ret*ai%mi;
        ai = ai*ai%mi;
        bi >>=1;
    }
    return ret;
}

void solve() {
    cin >>a >>x >>m;
    ll ct = 0;
    while((1ll<<(ct+1))-1 < x) {
        ct++;
    }
    ll u = 1;
    ll cur = 1;
    per(i,ct-1,-1) {
        ll mul;
        if((x>>i)&1) {
            mul = (fastexpo(a,u+1,m) + a)%m;
        } else {
            mul = (fastexpo(a,u,m)+1)%m;
        }
        cur = cur*mul%m;
        if((x>>i)&1) {
            cur = (cur+1)%m;
            u = u*2+1;
        } else {
            u = u*2;
        }
    }
    assert(u==x);
    cout <<cur%m <<"\n";
}

ll rnd(ll bw, ll at) {
    return bw + ((rand()%(at-bw+1)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    // for(ll i= 1e10;i<=1e10+10000;i++) {
    //     m = rnd(1,1e9);
    //     x = i;
    //     a = rnd(1,1e9);
    //     solve();

    // }
}