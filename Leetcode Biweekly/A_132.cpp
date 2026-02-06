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
    string clearDigits(string s) {
        vector<char> v;
        rep(i,0,sz(s)) {
            if(s[i]>='0' && s[i]<='9') {
                if(sz(v)) v.pop_back();
            } else {
                v.push_back(s[i]);
            }
        }
        string ans = "";
        rep(i,0,sz(v)) {
            ans += v[i];
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}