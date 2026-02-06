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
    int countDays(int days, vector<vector<int>>& meetings) {
        int ct = 0;
        vector<pii> v;
        rep(i,0,sz(meetings)) {
            v.push_back({meetings[i][0],meetings[i][1]});
        }
        sort(v.begin(),v.end());
        int r = 0;
        rep(i,0,sz(v)) {
            if(v[i].fi > r) {
                ct += (v[i].se-v[i].fi+1);
                r = v[i].se;
            } else {
                ct += max(v[i].se-r,0);
                max_self(r, v[i].se);
            }
        }
        return days-ct;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}