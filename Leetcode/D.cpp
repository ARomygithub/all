#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = sz(nums);
        int m = sz(changeIndices);
        vector dp(m+1, vector<ll>(n+1, (ll)(1e17)));
        map<int,int> mp;
        set<int> stemp;
        rep(i,0,m) {
            if(!stemp.count(changeIndices[i])) {
                mp[i] = changeIndices[i]-1;
                stemp.insert(changeIndices[i]);
            }
        }
        dp[0][0] = 0;
        rep(i,0,n) {
            dp[0][0] += nums[i]+1;
        }
        rep(i,1,m+1) {
            rep(j,0,n+1) {
                min_self(dp[i][j], dp[i-1][j]-1);
                if(j+1<=n) {
                    min_self(dp[i][j], dp[i-1][j+1]-1);
                }
                if(mp.count(i-1) && j>0) {
                    int ch = mp[i-1];
                    if(nums[ch]>0) {
                        min_self(dp[i][j], dp[i-1][j-1]-nums[ch]);
                    } 
                }
                // debug() <<imie(i) <<imie(j);
                // debug() <<imie(dp[i][j]);
            }
            // cout <<dp[i][0] <<"\n";
            if(dp[i][0]<=0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> ch = {1,3,2,2,2,2,3};
    sol.earliestSecondToMarkIndices(nums,ch);
}