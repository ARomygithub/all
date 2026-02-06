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

int msb(int a){
    if (a == 0) return 0;
    int wow = 1;
    while (a > 1){
        wow *= 2;
        a /= 2;
    }
    return wow;
}

void solve() {
    vector<vector<int>> sum(128,vector<int>(24,0));
    rep(i, 0, 7){
        rep(j, 0, 24){
            char tmp;
            cin >> tmp;
            if (tmp == '.') sum[1 << i][j] = 1;
            else sum[1 << i][j] = 0;
        }
    }
    int d,h;
    cin >> d >> h;
    for (int i = 0;i < (1 << 7);i++){
        // cout << i << endl;
        int li = msb(i);
        int ri = i - li;
        // cout << li << " " << ri << endl;
        for (int j = 0;j < 24;j++){
            sum[i][j] = sum[li][j] + sum[ri][j];
        }
    }
    int ansa = 0, ansb = 1;
    for (int i = 0;i < (1 << 7);i++){
        int dd = __builtin_popcount(i);
        if (dd < d) continue;
        sort(all(sum[i]), greater<int>());
        int tmpsum = 0;
        for (int j = 0;j < 24;j++){
            tmpsum += sum[i][j];
            if (j+1 >= h){
                if (tmpsum * ansb >= ansa * dd * (j+1)){
                    ansa = tmpsum;
                    ansb = dd * (j+1);
                }
            }
        }
    }
    cout << setprecision(7) << ansa * 1.0l / ansb << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}