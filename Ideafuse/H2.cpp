#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> v(16);
    for(int i=0; i<16; i++){
        cin >> v[i];
    }

    vector<vector<int>> m(17);
    m[1] = {7, 10};
    m[2] = {9, 11, 8};
    m[3] = {5, 10, 12};
    m[4] = {6, 11};
    m[5] = {3, 11, 14};
    m[6] = {4, 12, 15, 13};
    m[7] = {1, 9, 14, 16};
    m[8] = {10, 15, 2};
    m[9] = {15, 7, 2};
    m[10] = {1, 3, 8, 16};
    m[11] = {2, 5, 4, 13};
    m[12] = {3, 6, 14};
    m[13] = {6, 11};
    m[14] = {5, 7, 12};
    m[15] = {9, 6, 8};
    m[16] = {7, 10};


    vector<vector<ll>> dp(1<<16, vector<ll>(17, 0));
    // for(int i=0; i<16; i++){
    //     dp[(1<<i)][i+1] = v[i];
    // }
    vector<vector<int>> vx(17);
    for(int i=0; i<(1<<16); i++){
        int c = 0;
        for(int j=0; j<16; j++){
            if((i&(1<<j))){
                c++;
            }
        }
        vx[c].push_back(i);
    }

    // for(auto x: vx[1]){
    //     cout <<x << " ";
    // }
    // cout << "\n";

    for(int i=2; i<=16; i++){
        for(auto px: vx[i-1]){
            for(int j=0; j<16; j++){
                if(!(px & (1<<j))){
                    int mx = (px | (1<<j));
                    for(auto vv: m[j+1]){
                        if((px & (1<<(vv-1)))){
                            dp[mx][j+1] = max(dp[mx][j+1], dp[px][vv] + v[vv-1]*v[j]);
                        }
                    }
                }
            }   
        }
    }

    
    ll ans = 0;
    vector<int> bits;
    vector<int> ids;

    vector<vector<int>> vans;
    for(int i=1; i<(1<<16); i++){
        for(int j=0; j<16; j++){
            if(ans < dp[i][j+1] && (i&(1<<j))) {
                ans = max(dp[i][j+1], ans);
            }
        }
    }
    for(int i=0; i<(1<<16); i++){
        for(int j=0; j<16; j++){
            if(dp[i][j+1] == ans && (i&(1<<j))){
                bits.push_back(i);
                ids.push_back(j+1);
            }
        }
    }

    for(int i=1; i<=16; i++){
        sort(m[i].begin(), m[i].end());
    }

    for(int ii=0; ii<bits.size(); ii++){
        vector<int> tmp;
        int i = bits[ii];
        int j = ids[ii];
        tmp.push_back(j);
        ll cur = ans;
        while(cur > 0){
            int ij = ((i^(1<<(j-1))));
            vector<ll> vcur = dp[ij];
            for(auto k: m[j]){
                if((ij & (1<<(k-1)))){
                    ll cr = vcur[k];
                    if(cur - v[k-1]*v[j-1] == cr){
                        tmp.push_back(k);
                        break;
                    }
                }
            }
            cur -= v[tmp.back()-1]*v[j-1];
            i = (i^(1<<(j-1)));
            j = tmp.back();
        }
        reverse(tmp.begin(), tmp.end());
        vans.push_back(tmp);
    }
    sort(vans.begin(), vans.end());
    // for(auto vvv: vans){
    //     for(int i=0; i<vvv.size(); i++){
    //         cout << vvv[i] << " \n"[i==vvv.size()-1];
    //     }
    // }

    cout << ans << "\n";
    for(int i=0; i<vans[0].size(); i++){
        cout << vans[0][i] << " \n"[i==vans[0].size()-1];
    }

    
    

    return 0;
}