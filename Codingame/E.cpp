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
 * @param n The size of the image
 * @param target_image The rows of the desired image, from top to bottom
 */
vector<string> solve(int n, vector<string> target_image) {
  // Write your code here
    vector<pii> cl;
    rep(j,0,n) {
        int ct = 0;
        rep(i,0,n) {
            ct += target_image[i][j]=='#';
        }
        cl.push_back({ct,j});
    }
    sort(cl.begin(),cl.end());
    vector<string> ans;
    for(auto [ct, cli]: cl) {
        if(ct==0) continue;
        string cmd = "C ";
        cmd += (char)(cli+'0');
        ans.push_back(cmd);
        rep(i,0,n) {
            if(target_image[i][cli]=='.') {
                cmd = "R ";
                cmd += (char)(i+'0');
                ans.push_back(cmd);
            }
        }
    }
    if(sz(ans)==0) {
        ans.push_back("R 0");
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}