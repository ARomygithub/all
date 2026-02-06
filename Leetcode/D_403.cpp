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
    int min1(vector<vector<int>>& grid, int i1, int i2, int j1, int j2) {
        if(i1>i2 || j1>j2) return 0;
        int l = sz(grid[0])-1, r = 0;
        int u = sz(grid)-1, d=0;
        bool ada = 0;
        rep(i,i1,i2+1) {
            rep(j,j1,j2+1) {
                if(grid[i][j]==1) {
                    ada = 1;
                    min_self(l, j);
                    max_self(r, j);
                    min_self(u, i);
                    max_self(d, i);
                }
            }
        }
        if(!ada) return 0;
        return (r-l+1)*(d-u+1);
    }

    int min2(vector<vector<int>>& grid, int i1, int i2, int j1, int j2) {
        if(i1>i2 || j1>j2) return 0;
        int ans = sz(grid)*sz(grid[0]);
        rep(i,i1,i2+1) {
            int temp1 = min1(grid, i1, i, j1, j2);
            int temp2 = min1(grid, i+1, i2, j1, j2);
            min_self(ans, temp1+temp2);
        }
        rep(j,j1,j2+1) {
            int temp1 = min1(grid, i1, i2, j1, j);
            int temp2 = min1(grid, i1, i2, j+1, j2);
            min_self(ans, temp1+temp2);
        }        
        return ans;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int ans = sz(grid)*sz(grid[0]);
        rep(i,0,sz(grid)) {
            int temp1 = min1(grid, 0, i, 0, sz(grid[0])-1);
            int temp2 = min2(grid, i+1, sz(grid)-1, 0, sz(grid[0])-1);
            min_self(ans, temp1+temp2);
            temp2 = min2(grid, 0, i, 0, sz(grid[0])-1);
            temp1 = min1(grid, i+1, sz(grid)-1, 0, sz(grid[0])-1);
            min_self(ans, temp1 + temp2);
        }
        rep(j,0,sz(grid[0])) {
            int temp1 = min1(grid, 0, sz(grid)-1, 0, j);
            int temp2 = min2(grid, 0, sz(grid)-1, j+1, sz(grid[0])-1);
            min_self(ans, temp1+temp2);
            temp2 = min2(grid, 0, sz(grid)-1, 0, j);
            temp1 = min1(grid, 0, sz(grid)-1, j+1, sz(grid[0])-1);
            min_self(ans, temp1+temp2);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}