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
    int maximumLengthSubstring(string s) {
        int res = 1;
        vector<int> ct(26,0);
        int l=0,r=0;
        ct[s[0]-'a']++;
        while(r+1<sz(s)) {
            while(r+1<sz(s) && ct[s[r+1]-'a']<=1) {
                r++;
                ct[s[r]-'a']++;
            }
            max_self(res, r-l+1);
            if(l<r) {
                ct[s[l]-'a']--;
                l++;
            } else {
                l++;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}