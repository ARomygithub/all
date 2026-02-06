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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> r(sz(colors));
        int j = sz(colors);
        int prev = sz(colors)-1;
        r[sz(colors)-1] = sz(colors)-1;
        while(colors[j%sz(colors)]!=colors[prev%sz(colors)] && j<sz(colors)*2-1) {
            j++;
            prev++;
            r[sz(colors)-1]++;
        }
        per(i,sz(colors)-2,-1) {
            if(colors[i]==colors[i+1]) {
                r[i] = i;
            } else {
                r[i] = r[i+1];
            }
        }
        int ret = 0;
        rep(i,0,sz(colors)) {
            int len = r[i]-i+1;
            ret += (len>=k);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}