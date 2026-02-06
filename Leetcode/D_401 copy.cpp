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

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        bitset<100001> bs;
        bs.set(0);
        bitset<100001> mask;
        int idx = 0;
        rep(i,0,sz(rewardValues)) {
            while(idx<rewardValues[i]) {
                mask.set(idx, bs[idx]);
                idx++;
            }
            bs |= mask<<rewardValues[i];
        }
        int ans = 0;
        per(i,100000, -1) {
            if(bs[i]) {
                ans = i;
                break;
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