#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
int n=3;

bool isWin(vector<vector<char>> grid, char c) {
    for(int i=0;i<3;i++) {
        if(grid[i][0]==c && grid[i][1]==c && grid[i][2]==c) return true;
    }
    for(int j=0;j<3;j++) {
        if(grid[0][j]==c && grid[1][j]==c && grid[2][j]==c) return true;
    }
    bool flag=true;
    for(int i=0;i<3;i++) {
        flag &=grid[i][i]==c;
    }
    if(flag) return true;
    flag = 1;
    for(int i=0;i<3;i++) {
        flag &=grid[i][2-i]==c;
    }
    return flag;
}

void solve() {
    vector<pii> vb(9);
    for(int i=0;i<9;i++) {
        cin >>vb[i].fi >>vb[i].se; vb[i].fi--,vb[i].se--;
    }
    vector<pii> va(9);
    for(int i=0;i<9;i++) {
        va[i] = {i/3,i%3};
    }
    int ct=1e9;
    vector<pii> ans;
    do {
        vector<vector<char>> grid(3,vector<char>(3,'.'));
        vector<pii> temp;
        int idxb=0,idxa=0;
        while(true) {
            while(idxb<9 && grid[vb[idxb].fi][vb[idxb].se]!='.') {
                idxb++;
            }
            if(idxb==9) break;
            grid[vb[idxb].fi][vb[idxb].se] = '0';
            // temp2.push_back(vb[idxb]);
            // cout <<vb[idxb].fi <<" " <<vb[idxb].se <<"\n";
            if(isWin(grid, '0')) {
                if(sz(temp)<ct) {
                    // for(auto [a,b]: temp2) {
                    //     cout <<a <<" " <<b <<"\n";
                    // }
                    // for(auto [a,b]: temp) {
                    //     cout <<a <<" " <<b <<"\n";
                    // }
                    ct = sz(temp);
                    ans.swap(temp);
                }
                break;
            }
            while(idxa<9 && grid[va[idxa].fi][va[idxa].se]!='.') {
                idxa++;
            }
            if(idxa==9) break;
            grid[va[idxa].fi][va[idxa].se] = '1';
            // cout <<va[idxa].fi <<" " <<va[idxa].se <<"\n";
            temp.push_back(va[idxa]);
            if(isWin(grid, '1')) {
                break;
            }
        }
    } while(next_permutation(va.begin(),va.end()));
    for(auto [i,j]: ans) {
        cout <<i+1 <<" " <<j+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}