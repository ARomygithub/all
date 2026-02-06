#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second


void solve() {
    int n,k;
    cin >> n >> k;
    int done[n][n];
    int isShip[n][n];
    memset(done, false, sizeof(done));
    memset(isShip, false, sizeof(isShip));
    int target = k*5;
    for (int i = 0;i < n;i++){
        for (int j = i%5;j < n;j+= 5){
            cout << i+1 << " " << j+1 << endl << flush;
            done[i][j] = true;
            string inp;
            cin >> inp;
            if (inp == "hit" || inp == "sunk"){
                isShip[i][j] = true;
                target--;
                if (target == 0) return;
                for (int q = 0;q < 4;q++){
                    for (int y = 1;y <= 4;y++){
                        int in,ij;
                        if (q == 0) { in = i+y; ij = j; }
                        else if (q == 1) { in = i; ij = j+y; }
                        else if (q == 2) { in = i-y; ij = j; }
                        else if (q == 3) { in = i; ij = j-y; }

                        if (in < 0 || in >= n) continue;
                        if (ij < 0 || ij >= n) continue;
                        if (done[in][ij]){
                            if (isShip[in][ij]) continue;
                            else break;
                        } 
                        cout << in+1 << " " << ij+1 << endl << flush; 
                        done[in][ij] = true;
                        cin >> inp;
                        if (inp == "hit" || inp == "sunk"){
                            target--;
                            isShip[in][ij] = true;
                            if (target == 0) return;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}