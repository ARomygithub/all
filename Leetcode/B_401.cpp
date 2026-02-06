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

class Solution {
public:
    ll fastexpo(ll a, ll b, ll md) {
        ll ret =1;
        while(b) {
            if(b&1) {ret=(ret*a)%md;}
            a = (a*a)%md;
            b >>=1;
        }
        return ret;
    }    

    ll inv(ll a, ll md) {
        return fastexpo(a, md-2, md);
    }

    int valueAfterKSeconds(int n, int k) {
        ll mod = 1e9+7;
        int ret = 1;
        ll a = 1ll, b=1ll;
        rep(i,n,n+k) {
            a = a*i%mod;
        }
        rep(i,1,k+1) {
            b = b*i%mod;
        }
        a = a*inv(b, mod)%mod;
        ret = a;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}