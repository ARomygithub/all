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
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = sz(grid), m = sz(grid[0]);
        vector px(n, vector<int>(m,0));
        vector py(n, vector<int>(m,0));
        rep(i,0,n) {
            int tx = 0, ty=0;
            rep(j,0,m) {
                tx += (grid[i][j]=='X');
                ty += (grid[i][j]=='Y');
                px[i][j] = (i>0?px[i-1][j]:0) + tx;
                py[i][j] = (i>0?py[i-1][j]:0) + ty;
            }
        }
        int ans = 0;
        rep(i,0,n) {
            rep(j,0,m) {
                if(px[i][j]>0 && px[i][j]==py[i][j]) {
                    ans++;
                }
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