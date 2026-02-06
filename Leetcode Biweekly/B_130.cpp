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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<pic> v;
        rep(i,0,sz(points)) {
            v.push_back({max(abs(points[i][0]), abs(points[i][1])), s[i]});
        }
        sort(v.begin(), v.end());
        set<char> st;
        int ans = 0;
        for(int i=0;i<sz(v);) {
            int j =i;
            bool ok = 1;
            while(j < sz(v) && v[j].fi==v[i].fi) {
                if(st.count(v[j].se)) {
                    ok = 0;
                    break;
                } else {
                    st.insert(v[j].se);
                }
                j++;
            }
            if(ok) {
                ans = sz(st);
                i = j;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}