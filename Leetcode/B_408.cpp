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
    int nonSpecialCount(int l, int r) {
        int ans = r-l+1;
        const int mxn = 1e5;
        vector<bool> isPrime(mxn+1,1);
        for(int i=2;i*i<=r;i++) {
            if(isPrime[i]) {
                for(int j=i*2;j<=mxn;j+=i) {
                    isPrime[j] = 0;
                }
                if(i*i>=l) {
                    ans--;
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}