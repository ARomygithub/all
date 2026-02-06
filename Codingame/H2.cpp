#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int getA(int m, int mv) {
    int ret = mv^(mv>>1)^(mv<<1);
    if(ret>=(1<<m)) {
        ret -= (1<<m);
    }
    return ret;
}

/**
 * @param n_rows The number of rows in the target pattern.
 * @param n_cols The number of columns in the target pattern.
 * @param target_pattern The target pattern, row by row from left to right.
 * @return The shortest possible list of pixel coordinates to activate in order to reproduce the target pattern.
 */
vector<vector<int>> createPattern(int n_rows, int n_cols, vector<string> target_pattern) {
  // Write your code here
    vector<int> state;
    bool rev = n_rows<n_cols;
    int n = max(n_rows,n_cols);
    int m = min(n_rows,n_cols);
    // int ctp = 0;
    if(rev) {
        rep(i,0,n) {
            int temp = 0;
            rep(j,0,m) {
                if(target_pattern[j][i]=='#') {
                    temp += 1<<j;
                    // ctp++;
                }
            }
            state.push_back(temp);
        }
    } else {
        rep(i,0,n) {
            int temp = 0;
            rep(j,0,m) {
                if(target_pattern[i][j]=='#') {
                    temp += 1<<j;
                    // ctp++;
                }
            }
            state.push_back(temp);
        }
    }
    // cout <<"ctp " <<ctp <<"\n";
    int ans = 1e9;
    int mv0 = 0;
    rep(awl,0,(1<<m)) {
        int tmp = __builtin_popcount(awl);
        if(tmp>((m+1)/2) || (m>19 && tmp>((m+3)/4))) continue;
        vector<int> mv;
        mv.push_back(awl);
        rep(i,0,n-1) {
            int nxtmv = state[i]^getA(m,mv[i]);
            if(i>0) {
                nxtmv = nxtmv^mv[i-1];
            }
            mv.push_back(nxtmv);
            tmp += __builtin_popcount(nxtmv);
        }
        if(state[n-1] == (mv[n-2]^getA(m,mv[n-1]))) {
            if(tmp<ans) {
                mv0 = awl;
                ans = tmp;
            }
        }
        // cout <<awl <<endl;
    }
    vector<vector<int>> ret;
    rep(awl,mv0,mv0+1) {
        rep(i,0,m) {
            if((awl>>i)&1) {
                vector<int> tmp = {0,i};
                ret.push_back(tmp);
            }
        }
        vector<int> mv;
        mv.push_back(awl);
        rep(i,0,n-1) {
            int nxtmv = state[i]^getA(m,mv[i]);
            if(i>0) {
                nxtmv = nxtmv^mv[i-1];
            }
            mv.push_back(nxtmv);
            rep(j,0,m) {
                if((nxtmv>>j)&1) {
                    vector<int> tmp = {i+1,j};
                    ret.push_back(tmp);
                }
            }
        }
    }
    if(rev) {
        for(auto &reti : ret) {
            swap(reti[0],reti[1]);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n_rows = 22;
    int n_cols = 22;
    cin >>n_rows >>n_cols;
    vector<string> img(n_rows);
    rep(i,0,n_rows) {
        cin >>img[i];
    }
    auto ret = createPattern(n_rows,n_cols, img);
    cout <<sz(ret) <<"\n";
    for(auto reti: ret) {
        cout <<reti[0] <<" " <<reti[1] <<"\n";
    }
}