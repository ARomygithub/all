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
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        ll ret = 0;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int n = sz(enemyEnergies);
        if(currentEnergy<enemyEnergies[0]) return ret;
        ll s = 0;
        rep(i,1,n) {
            s += enemyEnergies[i];
        }
        s += currentEnergy;
        ret = s/enemyEnergies[0];
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}