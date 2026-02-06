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
    int solve(int i, int atas, vector<int>& rewardValues) {
        int ans = 0;
        if(rewardValues[i]*2-1 <=atas) {
            ans += rewardValues[i];
            atas = rewardValues[i]-1;
            i--;
            if(i>=0) {
                ans += solve(i, atas, rewardValues);
            }
            return ans;
        } else if(rewardValues[0]*2-1 >= atas) {
            auto it = upper_bound(rewardValues.begin(), rewardValues.end(), atas);
            if(it!=rewardValues.begin()) {
                it--;
                i = it-rewardValues.begin();
                ans += rewardValues[i];
            }
            return ans;
        } else {
            auto it = upper_bound(rewardValues.begin(), rewardValues.end(), atas);
            if(it!=rewardValues.begin()) {
                it--;
                i = it-rewardValues.begin();
                int one = 0;
                int j = i;
                while(j>=0 && rewardValues[j]*2-1>atas) {
                    int temp = rewardValues[j];
                    if(j>0) {
                        temp += solve(j-1, atas-temp, rewardValues);
                    }
                    max_self(one,temp);
                    j--;
                }
                if(j>=0) {
                    ans = rewardValues[j];
                    if(j>0) {
                        ans += solve(j-1,rewardValues[j]-1,rewardValues);
                    }
                }
                max_self(ans, one);
            }
            return ans;
        }
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int atas = 1e9;
        return solve(sz(rewardValues)-1,atas,rewardValues);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}