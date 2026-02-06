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
    vector<string> validStrings(int n) {
        vector<string> ret;
        rep(i,0,(1<<n)) {
            bool ok = 1;
            rep(j,0,n-1) {
                int b1 = (i>>j)&1;
                int b2 = (i>>(j+1))&1;
                if(b1==0 && b2==0) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) continue;
            string temp = "";
            rep(j,0,n) {
                int bi = (i>>j)&1;
                temp += (char)('0'+bi);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}