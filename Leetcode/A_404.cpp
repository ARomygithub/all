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
    int maxHeightOfTriangle(int red, int blue) {
        int ct = 0;
        int c1 =0, c2=0;
        if(red>blue) {
            swap(red,blue);
        }
        rep(i,1,150) {
            if(i%2) {
                c1 +=i;
            } else {
                c2 +=i;
            }
            if(red>=min(c1,c2) && blue>=max(c1,c2)) {
                ct++;
            } else {
                break;
            }
        }
        return ct;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}