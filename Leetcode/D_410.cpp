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

class Solution {
public:
    const ll mod = 1e9+7;
    const int mxa=3000;
    vector<ll> fct, ifc, iv;

    void init_fac() {
        fct.resize(mxa+1,0ll);
        ifc.resize(mxa+1,0);
        iv.resize(mxa+1,0);
        iv[1]=1;
        for(int i=2;i<=mxa;i++) {
            iv[i] = mod - mod/i*iv[mod%i]%mod;
        }
        fct[0]=1, ifc[0]=1;
        for(int i=1;i<=mxa;i++) {
            fct[i]=fct[i-1]*i%mod;
            ifc[i]=ifc[i-1]*iv[i]%mod;
        }
    }

    ll C(ll a, ll b) {
        if(a<b || a<0 || b<0) return 0;
        ll ret=fct[a];
        ret = ret*ifc[b] %mod;
        ret = ret*ifc[a-b] %mod;
        return ret;
    }

    int countOfPairs(vector<int>& nums) {
        init_fac();
        int sm = nums[0];
        int n = sz(nums);
        rep(i,0,n-1) {
            int temp = nums[i+1]-nums[i];
            if(temp<0) {
                sm += temp;
            }
        }
        ll ret = 0;
        if(sm>=0) {
            ret = C(sm+n, n);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}