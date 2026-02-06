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
    int maxOperations(string s) {
        int ret = 0;
        int k = 0, ls=-1;
        rep(i,0,sz(s)) {
            if(s[i]=='1') {
                if(ls!=-1) {
                    ret += ((i-ls-1) > 0)*k;
                }
                k++;
                ls = i;
            }
        }
        ret += ((sz(s)-1-ls)>0)*k;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}