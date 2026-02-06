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
        set<int> s;
        sort(rewardValues.begin(),rewardValues.end());
        rep(i,0,sz(rewardValues)) {
            set<int> toAdd;
            for(auto v : s) {
                if(v>=rewardValues[i]) {
                    break;
                } else {
                    toAdd.insert(v+rewardValues[i]);
                }
            }
            for(auto v: toAdd) {
                s.insert(v);
            }
            s.insert(rewardValues[i]);
        }
        int ans = *(--s.end());
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}