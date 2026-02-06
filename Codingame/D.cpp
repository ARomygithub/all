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

/**
 * @param n_rows The height of the image.
 * @param n_cols The width of the image.
 * @param image Pixels of the image, given row by row from top to bottom.
 * @return The parameters of the largest circle [centerRow, centerCol, radius].
 */
vector<int> findLargestCircle(int n_rows, int n_cols, vector<string> image) {
  // Write your code here
    int rmx = (min(n_rows,n_cols)-1)/2;
    per(r,rmx,0) {
        rep(i,r,n_rows-r) {
            rep(j,r,n_cols-r) {
                bool ok = 1;
                char c = image[i-r][j];
                rep(k,0,n_rows) {
                    rep(l,0,n_cols) {
                        int d = (k-i)*(k-i) + (l-j)*(l-j);
                        if(d>=r*r && d<(r+1)*(r+1)) {
                            if(image[k][l]!=c) {
                                ok = 0;
                                break;
                            }
                        }
                    }
                    if(!ok) break;
                }
                if(ok) {
                    vector<int> ret(3);
                    ret[0] = i; ret[1] = j; ret[2] = r;
                    return ret;
                }
            }
        }
    }
    return vector<int>(3,0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}