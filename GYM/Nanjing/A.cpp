#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int ti[4] = {0,1,0,-1};
const int tj[4] = {1,0,-1,0};

void solve() {
    int n,m;
    cin >> n >> m;
    char inp[n][m];
    rep(i,0,n){
        rep(j,0,m){
            cin >> inp[i][j];
        }
    }
    bool done[n][m], done2[n][m];
    memset(done, 0, sizeof(done));
    memset(done2, 0, sizeof(done2));
    vector<pair<vector<vector<bool>>, int>> area;
    rep(i,0,n){
        rep(j,0,m){
            if (inp[i][j] == '.' && !done[i][j]){
                queue<pair<pair<int,int>,pair<int,int>>> qw;
                qw.push({{i,j},{0,0}});
                done[i][j] = true;
                int mini = 9999, minj = 9999, maxi = -1, maxj = -1;
                int cnt = 0;
                while (!qw.empty()){
                    auto [posi,posj] = qw.front().first;
                    auto [relposi,relposj] = qw.front().second;
                    qw.pop();
                    mini = min(mini,relposi);
                    maxi = max(maxi,relposi);
                    minj = min(minj,relposj);
                    maxj = max(maxj,relposj);
                    cnt++;
                    rep(t,0,4){
                        int ni = posi+ti[t];
                        int nj = posj+tj[t];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && inp[ni][nj] == '.' && !done[ni][nj]){
                            done[ni][nj] = true;
                            qw.push({{ni,nj},{relposi+ti[t],relposj+tj[t]}});
                        }
                    }
                }
                vector<vector<bool>> tmpmat(maxi-mini+1, vector<bool>(maxj-minj+1,false));
                qw.push({{i,j},{-mini,-minj}});
                done2[i][j] = true;
                while (!qw.empty()){
                    auto [posi,posj] = qw.front().first;
                    auto [relposi,relposj] = qw.front().second;
                    qw.pop();
                    tmpmat[relposi][relposj] = true;
                    rep(t,0,4){
                        int ni = posi+ti[t];
                        int nj = posj+tj[t];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && inp[ni][nj] == '.' && !done2[ni][nj]){
                            done2[ni][nj] = true;
                            qw.push({{ni,nj},{relposi+ti[t],relposj+tj[t]}});
                        }
                    }
                }
                area.push_back({tmpmat,cnt});
            }
        }
    }
    // rep(t,0,area.size()){
    //     rep(i,0,area[t].first.size()){
    //         rep(j,0,area[t].first[0].size()){
    //             cout << area[t].first[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << area[t].second << endl;
    //     cout << "-------------" << endl;
    // }
    int an = area.size();
    int ans = 0;
    if (an == 0) {
        cout << 0 << endl;
    } else {
        
        rep(p, 0, an){
            bool isSubset = false;
            rep(q, 0, an){
                if (p==q) continue;
                int n1 = area[p].first.size();
                int m1 = area[p].first[0].size();
                int n2 = area[q].first.size();
                int m2 = area[q].first[0].size();

                if (n1 > n2 || m1 > m2) continue; 
                for(int y=0; y < n2-n1+1 && !isSubset; y++){
                    for(int x=0; x < m2-m1+1 && !isSubset; x++){
                        bool isAllOne = true;
                        for (int i=0; i < n1 && isAllOne; i++){
                            for(int j=0; j < m1 && isAllOne; j++){
                                if (area[p].first[i][j] == 1 && area[p].first[i][j] != area[q].first[y+i][x+j]){
                                    isAllOne = false;;
                                }
                            }
                        }
                        if (isAllOne) {
                            isSubset = true;
                        }
                    }
                }
                if (isSubset) break;
            }
            if (!isSubset){
                // cout << p << endl;
                ans += area[p].second;
                continue;
            }
        }
        cout <<  ans << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
}