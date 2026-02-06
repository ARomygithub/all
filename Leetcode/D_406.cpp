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
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ll ret = 0;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        ll sh=0, sv = 0;
        for(auto hi : horizontalCut) {
            sh += hi;   
        }
        for(auto vei : verticalCut) {
            sv += vei;
        }
        int ih=0,iv=0;
        while(ih<sz(horizontalCut) && iv<sz(verticalCut)) {
            if(horizontalCut[ih]>=verticalCut[iv]) {
                ret += horizontalCut[ih];
                ret += sv;
                sh -= horizontalCut[ih];
                ih++;
            } else {
                ret += verticalCut[iv];
                ret += sh;
                sv -= verticalCut[iv];
                iv++;
            }
        }
        while(ih<sz(horizontalCut)) {
            ret += horizontalCut[ih];
            ret += sv;
            sh -= horizontalCut[ih];            
            ih++;
        }
        while(iv<sz(verticalCut)) {
            ret += verticalCut[iv];
            ret += sh;
            sv -= verticalCut[iv];
            iv++;            
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}