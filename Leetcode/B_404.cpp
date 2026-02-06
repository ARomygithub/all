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
    int maximumLength(vector<int>& nums) {
        int k = 2;
        vector idx(k, vector<int>());
        rep(i,0,sz(nums)) {
            idx[nums[i]%k].push_back(i);
        }
        int ret = 0;
        rep(i,0,k) {
            rep(j,0,k) {
                if(i==j) {
                    max_self(ret, sz(idx[i]));
                    continue;
                }
                if(sz(idx[i])==0) continue;
                int temp = 1;
                int ia=1,ib=0;
                while(true) {
                    if(temp%2) {
                        while(ib<sz(idx[j]) && idx[j][ib]<idx[i][ia-1]) {
                            ib++;
                        }
                        if(ib<sz(idx[j])) {
                            temp++;
                            ib++;
                        } else {
                            break;
                        }
                    } else {
                        while(ia<sz(idx[i]) && idx[i][ia]<idx[j][ib-1]) {
                            ia++;
                        }
                        if(ia<sz(idx[i])) {
                            temp++;
                            ia++;
                        } else {
                            break;
                        }
                    }
                }
                max_self(ret, temp);
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}