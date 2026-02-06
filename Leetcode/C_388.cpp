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
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans(sz(arr), "");
        map<string,int> mp;
        rep(i,0,sz(arr)) {
            rep(len,1,sz(arr[i])+1) {
                set<string> temp;
                rep(j,0,sz(arr[i])-len+1) {
                    temp.insert(arr[i].substr(j,len));
                }
                for(auto si : temp) {
                    mp[si]++;
                }
            }
        }
        rep(i,0,sz(arr)) {
            rep(len,1,sz(arr[i])+1) {
                bool ok = 0;
                rep(j,0,sz(arr[i])-len+1) {
                    string cur = arr[i].substr(j,len);
                    if(mp[cur]==1) {
                        ok = 1;
                        if(ans[i]=="") {
                            ans[i] = cur;
                        } else {
                            min_self(ans[i], cur);
                        }
                    }
                }
                if(ok) break;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<string> cur = {"vbb","grg","lexn","oklqe","yxav"};
    auto ret = sol.shortestSubstrings(cur);
    for(auto si : ret) {
        cout <<si <<"\n";
    }
}