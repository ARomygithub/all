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
    int minimumArea(vector<vector<int>>& grid) {
        int l = sz(grid[0])-1, r = 0;
        int u = sz(grid)-1, d=0;
        rep(i,0,sz(grid)) {
            rep(j,0,sz(grid[i])) {
                if(grid[i][j]==1) {
                    min_self(l, j);
                    max_self(r, j);
                    min_self(u, i);
                    max_self(d, i);
                }
            }
        }
        return (r-l+1)*(d-u+1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}