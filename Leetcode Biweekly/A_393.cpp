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
    string findLatestTime(string s) {
        if(s[0]=='?') {
            s[0] = ((s[1]>='2'&&s[1]<='9')?'0':'1');
        }
        if(s[1]=='?') {
            s[1] = (s[0]=='1'?'1':'9');
        }
        if(s[3]=='?') {
            s[3] = '5';
        }
        if(s[4]=='?') {
            s[4] = '9';
        }
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}