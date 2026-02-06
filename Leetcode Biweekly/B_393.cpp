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
    bool isPrime(int x) {
        if(x==1) return false;
        for(int i=2;i*i<=x;i++) {
            if((x%i)==0) {
                return false;
            }
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int l = -1;
        rep(i,0,sz(nums)) {
            if(isPrime(nums[i])) {
                l = i;
                break;
            }
        }
        int r = -1;
        per(i,sz(nums)-1,-1) {
            if(isPrime(nums[i])) {
                r = i;
                break;
            }
        }
        return r-l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}