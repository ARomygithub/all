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
    int minimumDeletions(string word, int k) {
        vector<ll> ct(26,0);
        rep(i,0,sz(word)) {
            ct[word[i]-'a']++;
        }
        sort(ct.begin(),ct.end());
        vector<ll> pref(26);
        pref[0] = ct[0];
        rep(i,1,26) {
            pref[i] = pref[i-1]+ct[i];
        }
        ll ans = 2e9;
        rep(i,0,26) {
            ll temp = i>0?pref[i-1]:0;
            auto it = lower_bound(ct.begin(),ct.end(),ct[i]+k);
            if(it!=ct.end()) {
                int idx = it-ct.begin();
                temp += pref[25]-(idx>0?pref[idx-1]:0ll) - (ct[i]+k)*(26-idx);
            }
            // cout <<ct[i] <<" " <<temp <<"\n";
            min_self(ans, temp);
        }
        // cout <<"tes\n";
        // rep(i,0,26) {
        //     ll temp = pref[25]-(i>0?pref[i-1]:0ll) - (ct[i])*(26-i);
        //     auto it = upper_bound(ct.begin(),ct.end(),ct[i]-k);
        //     if(it!=ct.begin()) {
        //         it--;
        //         int idx = it-ct.begin();
        //         ll temp2 = (ct[i]-k)*(idx+1) - pref[idx];
        //         temp += temp2;
        //     }
        //     cout <<ct[i]-k <<" " <<temp <<"\n"; 
        //     min_self(ans, temp);
        // }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    int ret = sol.minimumDeletions("aabcaba",0);
    cout <<ret <<"\n";
}