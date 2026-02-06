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
typedef pair<int,char> pic;
class Solution {
public:
    string clearStars(string s) {
        vector id(26, vector<int>());
        rep(i,0,sz(s)) {
            if(s[i]=='*') {
                rep(j,0,26) {
                    if(sz(id[j])) {
                        id[j].pop_back();
                        break;
                    }
                }
            } else {
                id[s[i]-'a'].push_back(i);
            }
        }
        string ans = "";
        vector<pic> v;
        rep(i,0,26) {
            rep(j,0,sz(id[i])) {
                v.push_back({id[i][j], (char)('a'+i)});
            }
        }
        sort(v.begin(),v.end());
        rep(i,0,sz(v)) {
            ans += v[i].se;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    cout <<sol.clearStars("abc");
}